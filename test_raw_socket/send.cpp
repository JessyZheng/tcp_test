/**
 * send.c
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
#define IFRNAME1    "lo"

unsigned char source_mac[6] = {
   0};
unsigned char dest_mac[6] = {
   0};

int main(int argc,char **argv)
{
    int i ,datalen ,frame_length;
    int sd ,bytes;
    uint8_t data[IP_MAXPACKET];
    uint8_t ether_frame[IP_MAXPACKET];
    struct sockaddr_ll device;
    struct ifreq ifr;
    bzero(&device,sizeof(struct sockaddr_ll));
    bzero(&ifr,sizeof(struct ifreq));

    if((sd = socket(PF_PACKET,SOCK_DGRAM,htons(ETH_P_ALL))) < 0) {
        perror("socket() failed to get socket descriptor for using ioctl()");
        exit(EXIT_FAILURE);
    }
    //eth1
    memcpy(ifr.ifr_name,IFRNAME1,sizeof(struct ifreq));
    if(ioctl(sd,SIOCGIFHWADDR,&ifr) < 0) {
        perror("ioctl() failed to get source MAC address");
        return (EXIT_FAILURE);
    }
    close(sd);

    //copy source MAC address
    memcpy(source_mac,ifr.ifr_hwaddr.sa_data,6);

    memcpy(device.sll_addr,source_mac,6);
    if((device.sll_ifindex = if_nametoindex(IFRNAME1)) == 0) {
        perror("if_nametoindex() failed to obtain interface index");
        exit(EXIT_FAILURE);
    }
    // /*or*/ device.sll_addr = ifr.ifr_ifindex;
    device.sll_family = PF_PACKET;
    device.sll_halen = htons(6);
    //device.sll_protocol = htons(ETH_P_NP);

    // ifconfig eth2 /*00:0c:29:78:65:12*/
    dest_mac[0] = 0x00;
    dest_mac[1] = 0x0c;
    dest_mac[2] = 0x29;
    dest_mac[3] = 0x78;
    dest_mac[4] = 0x65;
    dest_mac[5] = 0x12;

    datalen = 9;
    data[0] = 'h';
    data[1] = 'e';
    data[2] = 'l';
    data[3] = 'l';
    data[4] = 'o';
    data[5] = ' ';
    data[6] = 'z';
    data[7] = 'o';
    data[8] = 'u';
    frame_length = 6 + 6 + 2 + datalen;

    /* 如果希望方便的话，可以尝试使用libnet */
    memcpy(ether_frame,dest_mac,6);
    memcpy(ether_frame + 6,source_mac,6);

    ether_frame[12] = ETH_P_NP / 256;
    ether_frame[13] = ETH_P_NP % 256;
    memcpy(ether_frame + 14,data,datalen);

    //one question : Here third parameters make me feel confused
    //if((sd = socket (PF_PACKET,SOCK_RAW,htons(ETH_P_NP))) < 0)
    if((sd = socket (PF_PACKET,SOCK_RAW,htons(ETH_P_ALL))) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        if ((bytes = sendto (sd, ether_frame, frame_length, 0, (struct sockaddr *)&device, sizeof (device))) <= 0) {
            perror("sendto() failed");
            exit(EXIT_FAILURE);
        }
        printf("send : %s\n", ether_frame);
        sleep(4);
    }

    close(sd);

    return 0;
}