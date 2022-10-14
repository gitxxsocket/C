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

#define SERVER_PORT 8888      //服务器的端口号
#define SERVER_IP "127.0.0.1" //服务器的 IP 地址

int main(int argc, char const *argv[])
{
    struct sockaddr_in server_addr = {0};
    char buf[512];
    int socketfd;
    int ret;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > socketfd)
    {
        perror("socket error\n");
        exit(EXIT_FAILURE);
    }

    /* 调用 connect 连接远端服务器 */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);            //端口号
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr); //IP 地址

    ret = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (0 > ret)
    {
        perror("connect error");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    printf("服务器连接成功...\n\n");

    /* 向服务器发送数据 */
    for (;;)
    {
        // 清理缓冲区
        memset(buf, 0x0, sizeof(buf));
        // 接收用户输入的字符串数据
        printf("Please enter a string: ");
        fgets(buf, sizeof(buf), stdin);
        // 将用户输入的数据发送给服务器
        ret = send(socketfd, buf, strlen(buf), 0);
        if (0 > ret)
        {
            perror("send error");
            break;
        }
        //输入了"exit"，退出循环
        if (0 == strncmp(buf, "exit", 4))
            break;
    }
    close(socketfd);
    exit(EXIT_SUCCESS);
}
