#ifndef SSLSERVER_H
#define SSLSERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include <functional>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

class Session
{
private:
    struct sockaddr_in  addr;
    int                 fd          = -1;
public:
    std::string         client_addr;

public:
    Session(struct sockaddr_in addr, int fd) :
            addr(addr),
            fd(fd)
    {
        char str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &addr.sin_addr, str, sizeof(str));
        int port = ntohs(addr.sin_port);

        client_addr = "["+std::string(str)+":"+std::to_string(port)+"]";
    };
private:
    const Session& operator=(const Session& rhis);
public:
    ~Session()
    {
        if (fd != -1)
        {
            close(fd);
        }
    };

public:
    int Send(uint8_t *buf, uint32_t len, uint32_t timeout_ms);
    int Recv(uint8_t *buf, uint32_t len, uint32_t timeout_ms);
};

class Server
{
private:
    std::string         ip;
    int                 port;
    struct sockaddr_in  addr;
private:
    int                 fd          = -1;

public:
    Server(const std::string ip, const int port) :
            ip(ip),
            port(port),
            addr((struct sockaddr_in) {
                    .sin_family = AF_INET,
                    .sin_port   = htons(port),
                    .sin_addr   = (struct in_addr){ .s_addr = inet_addr(ip.c_str()) },
            })
    {
    };

public:
    int Init(void);
    int Exit(void);
    int Accept(std::shared_ptr<Session> &session);
};

#endif //SSLSERVER_H
