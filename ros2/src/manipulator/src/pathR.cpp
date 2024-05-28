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

std::ifstream path("", std::ios::binary);

int data_size{BUF_SIZE};
char inputdata[BUF_SIZE] = {0};

int    fd;
int    poll_state;
char   buf[2];
struct termios    newtio;
struct pollfd     poll_events;

const int motor_num{7};
int motor[motor_num]={0};
int init_motor[motor_num]={0};

char data[BUF_SIZE];

unsigned char msg[1] = {0xCD};

short state{0};

int control_time{};

class Manipulator : public rclcpp::Node  // Node 1
{
    public:
    Manipulator() : Manipulator::Node("Pathreader")
    { // Define Topic msg
        motor_ = this->create_publisher<motor_interface::msg::Motor>("motor", 10);
        timer_ = this->create_wall_timer(std::chrono::microseconds(control_time), std::bind(&Manipulator::start_callback, this)); // control timer, control time = 10 ms
    }
    private:
    void start_callback()
    {
        auto Motor = motor_interface::msg::Motor();

        readPathData(path, BUF_SIZE, data);
        readPathData(path, BUF_SIZE, data);
        dataTransform(data, motor, motor_num);
        Motor.m1 = motor[0]; Motor.m2 = motor[1];
        Motor.m3 = motor[2]; Motor.m4 = motor[3];
        Motor.m5 = motor[4]; Motor.m6 = motor[5];
        Motor.m7 = motor[6]; Motor.st = (unsigned char)0xAB;
        motor_ -> publish(Motor);
        usleep(50000);
        readPathData(path, BUF_SIZE, data);
        dataTransform(data, motor, motor_num);
        Motor.m1 = motor[0]; Motor.m2 = motor[1];
        Motor.m3 = motor[2]; Motor.m4 = motor[3];
        Motor.m5 = motor[4]; Motor.m6 = motor[5];
        Motor.m7 = motor[6]; Motor.st = (unsigned char)0x00;
        motor_ -> publish(Motor);
        sleep(2);
        readPathData(path, BUF_SIZE, data);
        dataTransform(data, motor, motor_num);
        Motor.m1 = motor[0]; Motor.m2 = motor[1];
        Motor.m3 = motor[2]; Motor.m4 = motor[3];
        Motor.m5 = motor[4]; Motor.m6 = motor[5];
        Motor.m7 = motor[6]; Motor.st = (unsigned char)0xAA;
        motor_ -> publish(Motor);
        sleep(1);
        timer_ = this->create_wall_timer(std::chrono::microseconds(control_time), std::bind(&Manipulator::timer_callback, this));
    }
    void init_callback()
    {
        auto Motor = motor_interface::msg::Motor();

        readPathData(path, BUF_SIZE, data);
        Motor.m1 = motor[0]; Motor.m2 = motor[1];
        Motor.m3 = motor[2]; Motor.m4 = motor[3];
        Motor.m5 = motor[4]; Motor.m6 = motor[5];
        Motor.m7 = motor[6]; Motor.st = (unsigned char)0xAB;
        motor_ -> publish(Motor);
        usleep(50000);
        readPathData(path, BUF_SIZE, data);
        dataTransform(data, motor, motor_num);
        Motor.m1 = motor[0]; Motor.m2 = motor[1];
        Motor.m3 = motor[2]; Motor.m4 = motor[3];
        Motor.m5 = motor[4]; Motor.m6 = motor[5];
        Motor.m7 = motor[6]; Motor.st = (unsigned char)0x00;
        motor_ -> publish(Motor);
        sleep(2);
        readPathData(path, BUF_SIZE, data);
        dataTransform(data, motor, motor_num);
        Motor.m1 = motor[0]; Motor.m2 = motor[1];
        Motor.m3 = motor[2]; Motor.m4 = motor[3];
        Motor.m5 = motor[4]; Motor.m6 = motor[5];
        Motor.m7 = motor[6]; Motor.st = (unsigned char)0xAA;
        motor_ -> publish(Motor);
        sleep(1);
        timer_ = this->create_wall_timer(std::chrono::microseconds(control_time), std::bind(&Manipulator::timer_callback, this));
    }
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

        if((unsigned char)data[15]==0x02)
        {
            state=1;
            std::cout << "\x1b[38;5;9m[Expansion Port]\x1b[0m: ";
            std::cout<<"센서1 감지가 필요합니다.\n";
        }
        else if((unsigned char)data[15]==0x03)
        {
            state=2;
            std::cout << "\x1b[38;5;9m[Expansion Port]\x1b[0m: ";
            std::cout<<"센서2 감지가 필요합니다.\n";
        }
        else if((unsigned char)data[15]==0x04)
        {
            state=3;
            std::cout << "\x1b[38;5;9m[Expansion Port]\x1b[0m: ";
            std::cout<<"센서3 감지가 필요합니다.\n";
        }
        write(fd, msg, 1);
        readSerialData(&fd, poll_events, &poll_state, buf, 2);
        if(state==9 && (unsigned char)buf[1]==0x00)
        {
            state=0;
        }
        if(state==9 && ((unsigned char)buf[1]==0x02 || (unsigned char)buf[1]==0x03 || (unsigned char)buf[1]==0x04))
        {
            buf[1]==0x00;
        }
        while(state!=0&&state!=9)
        {
            write(fd, msg, 1);
            readSerialData(&fd, poll_events, &poll_state, buf, 2);
            if((unsigned char)buf[1]==state + 0x01)
            {
                std::cout << "\x1b[38;5;9m[Expansion Port]\x1b[0m: ";
                std::cout<<"센서"<<state<<" 감지됨.\n";
                state=9;
            }
            usleep(10000);
        }

        if (data[15]==(char)(0xFF))
        {
            path.clear();
            path.seekg(0, std::ios::beg);
            timer_ = this->create_wall_timer(std::chrono::microseconds(control_time), std::bind(&Manipulator::init_callback, this));
        }
    }
    rclcpp::Publisher<motor_interface::msg::Motor>::SharedPtr motor_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[])
{
    std::cout << "\x1b[38;5;39m3M_MANIPULATOR PATH READER v1.0\x1b[0m\n\n";
    usleep(100000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "ROS2 를 초기화중입니다...";
    rclcpp::init(argc, argv);
    auto node1 = std::make_shared<Manipulator>();
    std::cout << "완료!\n\n";
    usleep(100000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "컨트롤러와 연결중입니다...";
    if(openSerialPort(&fd,"/dev/arduinoMega")==-1)return -1;
    else std::cout << "완료!\n\n";
    usleep(100000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "Serial 통신을 위한 인자들을 초기화중입니다...";
    serialSetting(&fd, newtio, poll_events);
    std::cout << "완료!\n\n";
    usleep(100000);

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "불러올 PATH파일의 이름이 무엇입니까?\n";
    std::cout << "\x1b[38;5;226m[INPUT]\x1b[0m: ";
    std::cout << "File name : ";
    std::string file_name;
    std::cin >> file_name;
    std::cout << "\n\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "PATH파일을 불러오고 있습니다...";
    if(!openPathData(path, file_name))return -2;
    else std::cout << "완료!\n\n";

    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "경로 재생 배속을 입력해주새요. (정배속 구동 시 1 입력.)\n";
    std::cout << "\x1b[38;5;226m[INPUT]\x1b[0m: ";
    std::cout << "배속 : ";
    double time_in;
    std::cin >> time_in;
    control_time = 50000/time_in;

    usleep(100000);
    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "잠시만 기다려주세요..\n\n";
    sleep(1);
    std::cout << "\x1b[38;5;46m[SYSTEM]\x1b[0m: ";
    std::cout << "PATH 읽는중...\n";
    rclcpp::spin(node1);

    path.close();
    rclcpp::shutdown();
    return 0;
}