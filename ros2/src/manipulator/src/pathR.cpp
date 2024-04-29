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

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "motor_interface/msg/motor.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

std::ifstream path("", std::ios::binary);

int data_size{BUF_SIZE};
char inputdata[BUF_SIZE] = {0};

const int motor_num{7};
int motor[motor_num]={0};

char data[BUF_SIZE];

class Manipulator : public rclcpp::Node  // Node 1
{
    public:
    Manipulator() : Manipulator::Node("Pathreader")
    { // Define Topic msg
        motor_ = this->create_publisher<motor_interface::msg::Motor>("motor", 10);
        timer_ = this->create_wall_timer( 10ms, std::bind(&Manipulator::timer_callback, this)); // control timer, control time = 10 ms
    }
    private:
    void timer_callback()
    {
        auto Motor = motor_interface::msg::Motor();

        readPathData(path, BUF_SIZE, data);
        dataTransform(data, motor, motor_num);

        Motor.m1 = motor[0]; Motor.m2 = motor[1];
        Motor.m3 = motor[2]; Motor.m4 = motor[3];
        Motor.m5 = motor[4]; Motor.m6 = motor[5];
        Motor.m7 = motor[6]; Motor.st = (unsigned char)data[15];
        motor_ -> publish(Motor);

        if (data[15]==(char)(0xFF))
        {
            path.clear();
            path.seekg(0, std::ios::beg);
        }


    }
    rclcpp::Publisher<motor_interface::msg::Motor>::SharedPtr motor_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[])
{
    std::cout << "3M_MANIPULATOR PATH READER v1.0\n\n";
    usleep(1000000);
    std::cout << "ROS2 를 초기화중입니다...";
    rclcpp::init(argc, argv);
    auto node1 = std::make_shared<Manipulator>();
    std::cout << "완료!\n\n";
    usleep(1000000);
    std::cout << "불러올 PATH파일의 이름이 무엇입니까?\n";
    std::cout << "File name : ";
    std::string file_name;
    std::cin >> file_name;
    std::cout << "\nPATH파일을 불러오고 있습니다...";
    if(!openPathData(path, file_name)) return -1;
    else std::cout << "완료!\n\n";
    usleep(1000000);
    std::cout << "잠시만 기다려주세요..\n\n";
    sleep(3);
    std::cout << "PATH 읽는중...\n";
    rclcpp::spin(node1);
    path.close();
    rclcpp::shutdown();
    return 0;
}