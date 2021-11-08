#ifndef _TCP_SESSION_H_
#define _TCP_SESSION_H_

//#include <json/json.h>

void tcp_client_init(std::string msg, char* server_ip);
void tcp_server_init(void);

#endif /*_TCP_SESSION_H_*/