/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-01-28 22:11:45
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-01-29 13:31:58
 */

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

#define SERVER_PORT 5005
#define SERVER_IP "192.168.44.130"
const string quit = "quit";

int main()
{   
    //step1 socket()
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);               // port 5005
    inet_pton(AF_INET, SERVER_IP, (void *)&server.sin_addr.s_addr);      
    int sockFd = socket(AF_INET, SOCK_STREAM, 0); // using tcp protocal.

    //step2 bind()
    bind(sockFd, (sockaddr *)&server, sizeof(server));

    //step3 listen()
    listen(sockFd, 5);

    //step4 accept() -> 用多线程或者多进程处理已经建立好连接的客户端数据
    int newfd = accept(sockFd, nullptr, nullptr);

    //step5 read()
    while(1)
    {
        char buffer[BUFSIZ];
        memset(buffer, 0, BUFSIZ);
        read(newfd, buffer, BUFSIZ);
        cout << "receive data -> " << buffer << endl;
        if(strncasecmp(quit.c_str(), buffer, quit.size()) == 0)
        {
            cout << "client wants to close connect" << endl;
            break;
        }
    }

    close(newfd);
    close(sockFd);

    return 0;
}