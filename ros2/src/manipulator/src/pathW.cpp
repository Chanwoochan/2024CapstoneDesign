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
#include "pathRW.hpp"
#include "serial.hpp"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "motor_interface/msg/motor.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

std::ofstream rec_path("", std::ios::binary);

int data_size{BUF_SIZE};
char inputdata[BUF_SIZE] = {0};

int    fd;
int    poll_state;
char   buf[BUF_SIZE];
struct termios    newtio;
struct pollfd     poll_events;

const int motor_num{7};
int motor[motor_num]={0};

unsigned char msg[1] = {0xAB};

bool s_state{};

class Manipulator : public rclcpp::Node  // Node 1
{
    public:
    Manipulator() : Manipulator::Node("Controller")
    { // Define Topic msg
        motor_ = this->create_publisher<motor_interface::msg::Motor>("motor", 10);
        timer_ = this->create_wall_timer( 10ms, std::bind(&Manipulator::timer_callback, this)); // control timer, control time = 10 ms
    }
    private:
    void timer_callback()
    {
        auto Motor = motor_interface::msg::Motor();

        write(fd, msg, 1);
        readSerialData(&fd, poll_events, &poll_state, buf, BUF_SIZE);
        dataTransform(buf, motor, motor_num);
        char sw_state{buf[15]};
        if(s_state)
        {
            buf[15]=0x00;
        }
        writePathData(rec_path, BUF_SIZE, buf);
        Motor.m1 = motor[0]; Motor.m2 = motor[1];
        Motor.m3 = motor[2]; Motor.m4 = motor[3];
        Motor.m5 = motor[4]; Motor.m6 = motor[5];
        Motor.m7 = motor[6]; Motor.st = (unsigned char)buf[15];
        motor_ -> publish(Motor);

        if(!s_state&&(sw_state==(char)0x02||sw_state==(char)0x03||sw_state==(char)0x04))
        {
            std::cout << "\x1b[38;5;9m[Expansion Port]\x1b[0m: ";
            std::cout<<"센서"<<(int)buf[15]-0x01<<" 감지중...\n";
            s_state=1;
        }
        else if(s_state&&!(sw_state==(char)0x02||sw_state==(char)0x03||sw_state==(char)0x04))
        {
            std::cout << "\x1b[38;5;9m[Expansion Port]\x1b[0m: ";
            std::cout<<"센서"<<(int)buf[15]-0x01<<" 감지 종료.\n";
            s_state=0;
        }

        if(buf[15]==(char)0xFF)
        {
            rec_path.close();
            rclcpp::shutdown();
        }
    }

    rclcpp::Publisher<motor_interface::msg::Motor>::SharedPtr motor_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[])
{
    std::cout << "\x1b[38;5;39m3M_MANIPULATOR PATH WRITER v1.0\x1b[0m\n\n";
    usleep(1000000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "ROS2 를 초기화중입니다...";
    rclcpp::init(argc, argv);
    std::cout << "완료!\n\n";
    usleep(1000000);

    auto node1 = std::make_shared<Manipulator>();
    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "저장할 PATH파일의 이름이 무엇입니까?\n";
    std::cout << "\x1b[38;5;226m[INPUT]\x1b[0m: ";
    std::cout << "File name : ";
    std::string file_name;
    std::cin >> file_name;
    usleep(1000000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "컨트롤러와 연결중입니다...";
    if(openSerialPort(&fd,"/dev/arduinoMega")==-1) return -1;
    else std::cout << "완료!\n\n";
    usleep(1000000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "Serial 통신을 위한 인자들을 초기화중입니다...";
    serialSetting(&fd, newtio, poll_events);
    std::cout << "완료!\n\n";
    usleep(1000000);

    std::cout << "\n\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "PATH파일을 생성중입니다...";
    initPathData(rec_path, file_name);
    std::cout << "완료!\n\n";
    usleep(1000000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "잠시만 기다려주세요..\n\n";
    sleep(3);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "PATH 쓰는중...\n";
    rclcpp::spin(node1);
    
    rec_path.close();
    rclcpp::shutdown();

    return 0;
}