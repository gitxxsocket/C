#ifndef __1_H
#define __1_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 8888


#endif

int main(int argc, char const *argv[])
{

    struct sockaddr_in server_addr = {0};
    struct sockaddr_in client_addr = {0};

    char ip_str[20] = {0};

    int socketfd, connfd, ret;

    uint32_t addrlen = sizeof(client_addr);
    char recvbuf[512];

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > socketfd)
    {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    ret = bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (0 > ret)
    {
        perror("bind faild");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    ret = listen(socketfd, 3);
    if (0 > ret)
    {
        perror("lisetn faild");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    connfd = accept(socketfd, (struct sockaddr *)&client_addr, &addrlen);
    if (0 > connfd)
    {
        perror("accept faild");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    printf("connect start...........\n");
    inet_ntop(AF_INET, &client_addr.sin_addr, ip_str, sizeof(ip_str));
    printf("client address is : %s \n", ip_str);
    printf("client prot is : %d \n", client_addr.sin_port);

    while(1)
    {
        memset(recvbuf, 0x0, sizeof(recvbuf));
    
        ret = recv(connfd, recvbuf, sizeof(recvbuf), 0);
        if (0 > ret)
        {
            perror("lisetn faild");
            close(connfd);
            break;
        }

       printf("from client date : %s \n", recvbuf);
        if (0 == strncmp("exit", recvbuf, 4))
        {
            printf("server exit ... \n");
            close(connfd);
            break;
        }
          
    }

    close(socketfd);
    exit(EXIT_SUCCESS);

   
}
