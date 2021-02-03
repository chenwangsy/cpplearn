/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-01-27 22:18:42
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-01-27 22:42:25
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

int main()
{
    sockaddr_in receive;
    receive.sin_family = AF_INET;
    receive.sin_port = htons(13051);
    receive.sin_addr.s_addr = INADDR_ANY;

    sockaddr_in sender;
    sender.sin_family = AF_INET;
    sender.sin_port = htons(22222);
    sender.sin_addr.s_addr = INADDR_ANY;
    int sockFd = socket(AF_INET, SOCK_DGRAM, 0);
    bind(sockFd, (sockaddr *)&sender, sizeof(sender));


    int counter = 0;
    while (++counter <= 10)
    {
        sendto(sockFd, "chenwangairipi", 15, 0, (sockaddr *)&receive, sizeof(receive));
        sleep(2);
    }
    
    close(sockFd);
    
    
    return 0;
}