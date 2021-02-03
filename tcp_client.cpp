/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-01-28 22:11:45
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-01-29 13:48:05
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

    cout << connect(sockFd, (sockaddr *)&server, sizeof(server)) << endl;


    while(1)
    {  
        string buf;
        cout << "input what you want to send: ";
        cin >> buf;
        write(sockFd, buf.c_str(), buf.size() + 1);
        if(buf == quit)
        {
            cout << "client wants to close connect" << endl;
            break;
        }
    }
    cout << "after while" << endl;
    close(sockFd);

    return 0;
}