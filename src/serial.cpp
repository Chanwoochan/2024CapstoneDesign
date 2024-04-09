#define BUF_SIZE 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <termios.h>                   // B115200, CS8 등 상수 정의
#include <fcntl.h>                     // O_RDWR , O_NOCTTY 등의 상수 정의

#include <iostream>
#include <fstream>
#include "pathRW.hpp"
#include "serial.hpp"

int openSerialPort(int *fd)   // 시리얼 포트를 open
{
   *fd = open("/dev/arduinoMega", O_RDWR | O_NOCTTY );        // 디바이스를 open 한다.
   if ( 0 > *fd)
   {
      std::cout << "Serial open error\nPlease check connect Controller.";
      return -1;
   }
   return 0;
}

void serialSetting(int *fd, struct termios &newtio)       // 시리얼 포트 통신 환경 설정
{
   tcflush(*fd, TCIFLUSH);
   tcsetattr(*fd, TCSANOW, &newtio);
   fcntl(*fd, F_SETFL, FNDELAY);
}

int readSerialData(int *fd, struct pollfd &poll_events, int *poll_state, char *buf, std::ofstream &rec_path)
{
   *poll_state = poll(                                // poll()을 호출하여 event 발생 여부 확인
                     (struct pollfd*)&poll_events,  // event 등록 변수
                                                1,  // 체크할 pollfd 개수
                                             10 // time out 시간
                  );

   if (*poll_state > 0)                             // 발생한 event 가 있음
   {
      char temp[1];
      if ( poll_events.revents & POLLIN)            // event 가 자료 수신?
      {
         read( *fd, buf, BUF_SIZE);
         return 1;
      }
      if ( poll_events.revents & POLLERR)      // event 가 에러?
      {
         printf( "통신 라인에 에러가 발생, 프로그램 종료");
         return -1;
      }
   }
   else if(*poll_state < 0)
   {
         printf("Critial Error!\n");
         return -2;
   }
   else if(*poll_state == 0)
   {
         //printf("wait...\n");
   }
   return 0;
}