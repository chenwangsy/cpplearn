/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-01-27 21:48:10
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-01-27 22:39:43
 */

#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stddef.h>
#include <memory>
#include <string.h>
#include <iostream>
using namespace std;

class UdpReceiver
{
    public:
        UdpReceiver(int port);
        ~UdpReceiver() {close(socketFD_);}
        UdpReceiver(const UdpReceiver &rhs) = delete;
        UdpReceiver& operator=(const UdpReceiver &rhs) = delete;

        int receive();
    private:
        sockaddr_in receiver_;
        sockaddr_in sender_;
        int port_;
        int socketFD_;
        
    
};

UdpReceiver::UdpReceiver(int port) : port_(port)
{
    receiver_.sin_family = AF_INET;
    receiver_.sin_port = htons(port_);
    receiver_.sin_addr.s_addr = INADDR_ANY;
    int sockFd = socket(AF_INET, SOCK_DGRAM, 0);
    socketFD_ = sockFd;
    bind(socketFD_, (sockaddr *)&receiver_, sizeof(receiver_));
}

int UdpReceiver::receive()
{   
    const int bufSize = 128;
    char buf[bufSize];
    memset(buf, 0, bufSize);
    socklen_t len = sizeof(sender_);
    int receiveSize = recvfrom(socketFD_, (void *)buf, bufSize, 0, (sockaddr *)&sender_, &len);
    cout << "received data is -> " << buf << endl;
    cout << "sender ip -> " << inet_ntoa(sender_.sin_addr) << "sender port -> " << ntohs(sender_.sin_port) << endl;
    return receiveSize;
}








#endif //UDPRECEIVER_H