#include "Server.h"

int Session::Send(uint8_t *buf, uint32_t len, uint32_t timeout_ms)
{
    auto process_time = std::chrono::steady_clock::now();

    uint32_t   cnt = 0;
    while (cnt < len)
    {
        {
            int ret = send(fd, buf + cnt, len - cnt, 0);
            int err = errno;
            if (ret > 0)
            {
                cnt += ret;
                continue;
            }
            if (err != EAGAIN && err != EWOULDBLOCK)
            {
                return -1;
            }
        }

        if(cnt == len)
        {
            break;
        }

        auto compare_time = std::chrono::steady_clock::now() - std::chrono::milliseconds(timeout_ms);
        if (compare_time >= process_time)
            break;
        else
            std::this_thread::sleep_for(std::min(std::chrono::milliseconds(10), std::chrono::duration_cast<std::chrono::milliseconds>(process_time - compare_time)));
    }

    return  cnt;
}

int Session::Recv(uint8_t *buf, uint32_t len, uint32_t timeout_ms)
{
    auto process_time = std::chrono::steady_clock::now();

    uint32_t   cnt = 0;
    while (cnt < len)
    {
        {
            int ret = recv(fd, buf + cnt, len - cnt, 0);
            int err = errno;
            if (ret > 0)
            {
                cnt += ret;
                continue;
            }
            if (err != EAGAIN && err != EWOULDBLOCK)
            {
                return -1;
            }
        }
        if(cnt == len)
        {
            break;
        }

        auto compare_time = std::chrono::steady_clock::now() - std::chrono::milliseconds(timeout_ms);
        if (compare_time >= process_time)
            break;
        else
            std::this_thread::sleep_for(std::min(std::chrono::milliseconds(10), std::chrono::duration_cast<std::chrono::milliseconds>(process_time - compare_time)));
    }

    return  cnt;
}


int Server::Init(void)
{
    int                 ret;
    int                 opt;

    ret = socket(AF_INET, SOCK_STREAM, 0);
    if (ret == -1)
    {
        std::cout << "create tcp socket failed(" << std::endl;
        goto FAIL_TCP;
    }
    fd = ret;

    opt = 1;
    ret = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (ret == -1)
    {
        std::cout << "set tcp socket SO_REUSEADDR failed(" << std::endl;
        goto FAIL_TCP;
    }

    ret = bind(fd, (struct sockaddr*) &addr, sizeof(addr));
    if (ret == -1)
    {
        std::cout << "bind tcp socket failed(" << std::endl;
        goto FAIL_TCP;
    }

    ret = listen(fd, SOMAXCONN);
    if (ret == -1)
    {
        std::cout << "listen tcp socket failed(" << std::endl;
        goto FAIL_TCP;
    }

    return 0;

FAIL_TCP:
    if (fd  != -1)
    {
        close(fd);
        fd = -1;
    }

    return -1;
}

int Server::Exit(void)
{
    if (fd != -1)
    {
        close(fd);
        fd = -1;
    }

    return 0;
}

int Server::Accept(std::shared_ptr<Session> &session)
{
    int                 ret;
    socklen_t           len;

    struct sockaddr_in  sessionAddr;
    int                 sessionFd          = -1;

    len = sizeof(sessionAddr);
    ret = accept(fd, (struct sockaddr *)&sessionAddr, &len);
    if (ret == -1)
    {
        std::cout << "accept tcp socket failed(" << std::endl;
        return -1;
    }
    sessionFd = ret;

    auto process_time = std::chrono::steady_clock::now();

    ret = fcntl(sessionFd, F_GETFL, 0);
    ret = fcntl(sessionFd, F_SETFL, ret | O_NONBLOCK | O_NDELAY);
    if (ret == -1)
    {
        std::cout << "set tcp socket status flags failed(" << std::endl;
        goto FAIL_TCP;
    }

    session = std::make_shared<Session>(sessionAddr, sessionFd);
    return 0;

FAIL_TCP:
if (sessionFd  != -1)
{
    close(sessionFd);
    sessionFd = -1;
}

    return  1;
}
