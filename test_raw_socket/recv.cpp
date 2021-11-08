/**
 * recv.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/if_ether.h>
#include <bits/ioctls.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <errno.h>

#define ETH_P_NP    0x0807
#define IFRNAME0    "eth0"
#define IFRNAME2    "lo"

unsigned char dest_mac[6] = {
   0};

int main(int argc,char **argv)
{
    int i ,datalen;
    int sd ;
    unsigned char data[IP_MAXPACKET] = {
   0};
    unsigned char *buf = NULL;

    struct sockaddr_ll device;
    struct ifreq ifr;
    socklen_t sll_len = sizeof(struct sockaddr_ll);
    bzero(&device,sizeof(struct sockaddr_ll));
    bzero(&ifr,sizeof(struct ifreq));

    if((sd = socket(PF_PACKET,SOCK_DGRAM,htons(ETH_P_ALL))) < 0) {
        perror("socket() failed to get socket descriptor for using ioctl()");
        exit(EXIT_FAILURE);
    }
    memcpy(ifr.ifr_name,IFRNAME2,sizeof(struct ifreq));
    if(ioctl(sd,SIOCGIFHWADDR,&ifr) < 0) {
        perror("ioctl() failed to get source MAC address");
        return (EXIT_FAILURE);
    }
    close(sd);

    memcpy(dest_mac,ifr.ifr_hwaddr.sa_data,6);

    memcpy(device.sll_addr,dest_mac,6);
    device.sll_ifindex = ifr.ifr_ifindex;
    device.sll_family = PF_PACKET;
    device.sll_halen = htons(6);
    device.sll_protocol = htons(ETH_P_NP);

    if((sd = socket (PF_PACKET,SOCK_RAW,htons(ETH_P_NP))) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        datalen = recvfrom(sd,data,1024,0,(struct sockaddr *)&device,&sll_len);
        if (datalen < 0) { printf("error\n"); exit(-1); }
        buf = data + 14;
        printf("ip data : %s\n",buf);
        memset(data, 0, sizeof(data));
    }
    return 0;
}