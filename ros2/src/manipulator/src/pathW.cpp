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
        writePathData(rec_path, BUF_SIZE, buf);
        dataTransform(buf, motor, motor_num);

        Motor.m1 = motor[0]; Motor.m2 = motor[1];
        Motor.m3 = motor[2]; Motor.m4 = motor[3];
        Motor.m5 = motor[4]; Motor.m6 = motor[5];
        Motor.m7 = motor[6]; Motor.st = (unsigned char)buf[15];
        motor_ -> publish(Motor);
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
    std::cout << "3M_MANIPULATOR PATH WRITER v1.0\n\n";
    usleep(1000000);
    std::cout << "ROS2 를 초기화중입니다...";
    rclcpp::init(argc, argv);
    std::cout << "완료!\n\n";
    usleep(1000000);
    auto node1 = std::make_shared<Manipulator>();
    std::cout << "Serial 통신을 위한 인자들을 초기화중입니다...";
    memset(&newtio, 0, sizeof(newtio) );
    newtio.c_cflag       = B1000000 | CS8 | CLOCAL | CREAD;
    newtio.c_oflag       = 0;
    newtio.c_lflag       = 0;
    newtio.c_cc[VTIME]   = 0;
    newtio.c_cc[VMIN]    = 1;
    std::cout << "완료!\n\n";
    usleep(1000000);
    std::cout << "저장할 PATH파일의 이름이 무엇입니까?\n";
    std::cout << "File name : ";
    std::string file_name;
    std::cin >> file_name;
    usleep(1000000);
    std::cout << "컨트롤러와 연결중입니다...";
    if(openSerialPort(&fd,"/dev/arduinoMega")==-1) return -1;
    else std::cout << "완료!\n\n";
    usleep(1000000);
    serialSetting(&fd, newtio);
    poll_events.fd        = fd;
    poll_events.events    = POLLIN | POLLERR;
    poll_events.revents   = 0;
    std::cout << "\nPATH파일을 생성중입니다...";
    initPathData(rec_path, file_name);
    std::cout << "완료!\n\n";
    usleep(1000000);
    std::cout << "잠시만 기다려주세요..\n\n";
    sleep(3);
    std::cout << "PATH 쓰는중...\n";
    rclcpp::spin(node1);
    rec_path.close();
    rclcpp::shutdown();

    return 0;
}