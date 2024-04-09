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

int main()
{
    // ==============WritePath========================
    std::ofstream rec_path("", std::ios::binary);
    std::cout << "File name : ";
    std::string file_name;
    std::cin >> file_name;

    int data_size{BUF_SIZE};
    char inputdata[BUF_SIZE] = {0};

    int    fd;
    int    ndx;
    char   buf[BUF_SIZE];
    struct termios    newtio;
    struct pollfd     poll_events;      // 체크할 event 정보를 갖는 structs
    int    poll_state;

    memset(&newtio, 0, sizeof(newtio) );
    newtio.c_cflag       = B1000000 | CS8 | CLOCAL | CREAD;
    newtio.c_oflag       = 0;
    newtio.c_lflag       = 0;
    newtio.c_cc[VTIME]   = 0;
    newtio.c_cc[VMIN]    = 1;

    if(openSerialPort(&fd)==-1) return -1;
    serialSetting(&fd, newtio);

    // poll 사용을 위한 준비
    poll_events.fd        = fd;
    poll_events.events    = POLLIN | POLLERR;          // 수신된 자료가 있는지, 에러가 있는지
    poll_events.revents   = 0;

    // close( fd);
    // return 0;

    struct timespec  begin, end;

    initPathData(rec_path, file_name);

    std::cout << "Wait Writing..\n";
    sleep(3);

    const int motor_num{7};
    int motor[motor_num]={0};

    unsigned char msg[1] = {0xAB};

    int count{0};
    while(true)
    {
        clock_gettime(CLOCK_MONOTONIC, &begin);
        write(fd, msg, 1);
        readSerialData(&fd, poll_events, &poll_state, buf, rec_path);
        writePathData(rec_path, BUF_SIZE, buf);
        std::cout << "Time: " << (double)(count * 10 * 0.001) << "s\t>>> ";
        // std::cout << buf << "\n";
        count++;

        dataTransform(buf, motor, motor_num);
        std::cout << "motor1: " << motor[0] << "\t";
        std::cout << "motor2: " << motor[1] << "\t";
        std::cout << "motor3: " << motor[2] << "\t";
        std::cout << "motor4: " << motor[3] << "\t";
        std::cout << "motor5: " << motor[4] << "\t";
        std::cout << "motor6: " << motor[5] << "\t";
        std::cout << "motor7: " << motor[6] << "\n";
        if(buf[15]==(char)(0xFF)) break;

        while(1)
        {
            clock_gettime(CLOCK_MONOTONIC, &end);
            unsigned long time = (end.tv_nsec - begin.tv_nsec);
            if(time >= 10000000) break;
        }
    }

    close(fd);

    rec_path.close();

    // ==============ReadPath=========================

    std::cout << "Wait Reading..\n";
    sleep(3);

    std::ifstream path("", std::ios::binary);
    if(!openPathData(path, file_name)) return 0;

    count = 0;
    while(true)
    {
        clock_gettime(CLOCK_MONOTONIC, &begin);
        char data[BUF_SIZE];
        readPathData(path, BUF_SIZE, data);
        std::cout << "Time: " << (double)(count * 10 * 0.001) << "s\t>>> ";
        count++;
        dataTransform(data, motor, motor_num);
        std::cout << "motor1: " << motor[0] << "\t";
        std::cout << "motor2: " << motor[1] << "\t";
        std::cout << "motor3: " << motor[2] << "\t";
        std::cout << "motor4: " << motor[3] << "\t";
        std::cout << "motor5: " << motor[4] << "\t";
        std::cout << "motor6: " << motor[5] << "\t";
        std::cout << "motor7: " << motor[6] << "\n";
        if (data[15]==(char)(0xFF))
        {
            path.clear();
            path.seekg(0, std::ios::beg);
            // path.close();
            // if(!openPathData(path, file_name))
            //     return 0;
        }

        while(1)
        {
            clock_gettime(CLOCK_MONOTONIC, &end);
            unsigned long time = (end.tv_nsec - begin.tv_nsec);
            if(time >= 10000000) break;
        }
    }

    path.close();

    return 0;
}