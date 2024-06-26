#ifndef SERIAL_HPP
#define SERIAL_HPP

int openSerialPort(int *fd, char device[]);
void serialSetting(int *fd, struct termios &newtio,struct pollfd &poll_events);
int readSerialData(int *fd, struct pollfd &poll_events, int *poll_state, char *buf, int buf_size);

#endif