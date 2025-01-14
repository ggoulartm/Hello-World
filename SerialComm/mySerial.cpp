extern "C" {
#include <asm/termbits.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
}
#include <iostream>
#include "mySerial.h"

using namespace std;

mySerial::mySerial(string deviceName, int baud){
handle = -1;
Open(deviceName,baud);
}

mySerial::~mySerial(){
    if(handle>=0) Close();
}

void mySerial::Close(void){
if(handle >=0)
close(handle);
handle = -1;
}

bool mySerial::isOpen(void){
    return(handle>=0);
}

bool mySerial::Send(unsigned char value){
    if(!isOpen()) return false;
    int rlen = write(handle, &value, 1);
    return(rlen==1);
}

bool mySerial::Send(string value){
    if(!isOpen()) return false;
    int rlen = write(handle, value.c_str(), value.size());
    return(rlen == value.size());
}

bool mySerial::Send(unsigned char *data, int len){
    if(!isOpen()) return false;
    int rlen = write(handle, data, len);
    return(rlen == len);
}

int mySerial::Receive(unsigned char *data, int len){
    if(!isOpen()) return -1;
    //this is a blocking receives
    int lenRCV=0;
    while(lenRCV<len){
        int rlen=read(handle, &data[lenRCV], len - lenRCV);
        lenRCV+=rlen;
    }
    return lenRCV;
}

bool mySerial::NumberByteRcv(int &bytelen){
if(!isOpen()) return false;
ioctl(handle, FIONREAD, &bytelen);
return true;
}

bool mySerial::Open(string deviceName , int baud){
struct termios tio; struct termios2 tio2;
this->deviceName=deviceName; this->baud=baud;
handle = open(this->deviceName.c_str(),O_RDWR | O_NOCTTY /* | O_NONBLOCK */);
if(handle <0) return false;
tio.c_cflag = CS8 | CLOCAL | CREAD;
tio.c_oflag = 0;
tio.c_lflag = 0; //ICANON;
tio.c_cc[VMIN]=0;
tio.c_cc[VTIME]=1; // time out every .1 sec
ioctl(handle,TCSETS,&tio);
ioctl(handle,TCGETS2,&tio2);
tio2.c_cflag &= ~CBAUD;
tio2.c_cflag |= BOTHER;
tio2.c_ispeed = baud;
tio2.c_ospeed = baud;
ioctl(handle,TCSETS2,&tio2);
// flush buffer
ioctl(handle,TCFLSH,TCIOFLUSH);
return true;
}

