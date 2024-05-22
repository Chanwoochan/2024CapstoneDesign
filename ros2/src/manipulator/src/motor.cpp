/********************************************************************
 * @file Main.cpp_for_JUJODANJO's_Manipulator
 * @name Chan_woo Kim
 * @version Alpha 1.0.0_
 * @copyright Chan_woo Kim
 *
 * !무단 수정 금지!
 ********************************************************************/

#define BUF_SIZE 16
#define MSG_SIZE 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <termios.h>                   // B115200, CS8 등 상수 정의
#include <fcntl.h>                     // O_RDWR , O_NOCTTY 등의 상수 정의
#include <unistd.h>
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>

#include <chrono>

#include "serial.hpp"
#include "pathRW.hpp"
#include "dynamixel_protocols.hpp"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "motor_interface/msg/motor.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

int    fd;
int    poll_state;
char   buf[BUF_SIZE];
struct termios    newtio;
struct pollfd     poll_events;

class Manipulator : public rclcpp::Node  // Node 1
{
    public:
    Manipulator() : Manipulator::Node("Manipulator")
    { // Define Topic msg
        motor_ = this->create_subscription<motor_interface::msg::Motor>("motor", 1, std::bind(&Manipulator::control_callback, this, _1));
    }
    private:
    void control_callback(motor_interface::msg::Motor::SharedPtr msg)
    {

        motor_position_control(fd, 1, (unsigned short)(818.1 + (double)(msg->m1)*2.4917));

        motor_position_control(fd, 2, (unsigned short)(818.1 + (double)(msg->m2)*2.4917));
        motor_position_control(fd, 6, (unsigned short)(4095 - 818.1 - (double)(msg->m2)*2.4917));

        motor_position_control(fd, 3, (unsigned short)(818.1 + (double)(msg->m3)*2.4917));
        motor_position_control(fd, 4, (unsigned short)(818.1 + (double)(msg->m4)*2.4917));
        motor_position_control(fd, 5, (unsigned short)(818.1 + (double)(msg->m5)*2.4917));

        if((msg->m7) > 512)
            motor_velocity_control(fd, 7, (msg->m7)*2 - 1024);
        else
            motor_position_control(fd, 7, 2047);
    }
    rclcpp::Subscription<motor_interface::msg::Motor>::SharedPtr motor_;
};

int main(int argc, char*argv[])
{
    std::cout << "\x1b[38;5;39m3M_MANIPULATOR v1.0\x1b[0m\n\n";
    usleep(1000000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "ROS2 를 초기화중입니다...";
    rclcpp::init(argc, argv);
    auto node1 = std::make_shared<Manipulator>();
    std::cout << "완료!\n\n";
    usleep(1000000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "매니퓰레이터와 연결중입니다...";
    if(openSerialPort(&fd,"/dev/u2d2")==-1) return -1;
    else std::cout << "완료!\n\n";
    usleep(1000000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "Serial 통신을 위한 인자들을 초기화중입니다...";
    serialSetting(&fd, newtio, poll_events);
    std::cout << "완료!\n\n";
    usleep(1000000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "잠시만 기다려주세요..\n\n";
    sleep(1);

    for(unsigned char i{1};i<=7;i++)
    {
        // motor_p_gain(fd, i, 600);
        // motor_d_gain(fd, i, 4000);
        motor_torque_e(fd, i);
    }
    for(unsigned char i{1}; i<=7; i++ )
    {
        motor_Profile_v(fd, i, 6000);
        motor_Profile_a(fd, i, 6000);
    }
    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "위치를 초기화합니다.\n";
    position_init(fd, 2000);  // Runtime : 2000 msec
    for(unsigned char i{1}; i<=7; i++ )
    {
        motor_Profile_v(fd, i, 0);
        motor_Profile_a(fd, i, 0);
    }
    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "위치제어중입니다.\n";
    rclcpp::spin(node1);

    rclcpp::shutdown();
    return 0;
}