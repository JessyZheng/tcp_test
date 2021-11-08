#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "json.hpp"
#include "tcp_session.h"

#define MAXLINE 4096

void tcp_client_init(std::string msg, char * server_ip)
{
    int   sockfd, n;
    char  recvline[4096], sendline[4096];
    struct sockaddr_in  servaddr;

    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
        return;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    if( inet_pton(AF_INET, server_ip, &servaddr.sin_addr) <= 0){
        printf("inet_pton error for %s\n",server_ip);
        return;
    }

    if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
        return;
    }

    printf("send msg to server: \n");
    if( send(sockfd, msg.c_str(), msg.length(), 0) < 0){
        printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
        return;
    }
    close(sockfd);
    printf("send msg %s success!\n", msg.c_str());
}

void tcp_server_init(void)
{
    int  listenfd, connfd;
    struct sockaddr_in  servaddr;
    char  buff[4096];
    int  n;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        return;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        return;
    }

    if( listen(listenfd, 10) == -1){
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        return;
    }

    printf("======waiting for client's request======\n");
    while(1)
    {
        if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
            printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
            continue;
        }
        n = recv(connfd, buff, MAXLINE, 0);
        buff[n] = '\0';
        printf("recv msg from client: %s\n", buff);
        std::string  msg_data(buff, n);
        nlohmann::json msg_json;
        try {
            msg_json = nlohmann::json::parse(msg_data);
        } catch (std::exception& e) {
        }

        auto tray_read = msg_json["trays"];
        auto binId = tray_read[0]["binId"];

        std::cout << "binId: " << binId << std::endl;
        close(connfd);
    }
    close(listenfd);
    return;
}

