#include "unp.h"

void dg_cli(FILE* fp, int sockfd, const struct sockaddr* pservaddr, socklen_t servlen);

int main(int argc, char * argv[])
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    if(argc != 2) {
        err_quit("usage: udpcli <IPaddr>");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    dg_cli(stdin, sockfd, (SA*)&servaddr, sizeof(servaddr));

    exit(0);
}

void dg_cli(FILE* fp, int sockfd, const struct sockaddr* pservaddr, socklen_t servlen)//协议无关的
{
    int n;
    char sendline[MAXLINE], recvline[MAXLINE];
    while(fgets(sendline, MAXLINE, fp) != NULL) {
        sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

        n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL); //可以接受来自任何（不仅仅是目标服务器端）的信息，只要知道客户端的临时端口号就可以

        recvline[n] = '\0';
        fputs(recvline, stdout);
    }
}


/**
 * 丢弃来自非目标服务器的消息
*/
void dg_cli02(FILE* fp, int sockfd, const struct sockaddr* pservaddr, socklen_t servlen)
{
    int n;
    char sendline[MAXLINE], recvline[MAXLINE];
    socklen_t len;
    struct sockaddr *preply_addr;

    preply_addr = malloc(servlen);

    while(fgets(sendline, MAXLINE, fp) != NULL) {
        sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

        len = servlen;

        n = recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
        if(len != servlen || memcmp(pservaddr, preply_addr, len) != 0) {
            printf("reply from other server (ignored)\n");
            continue;
        }

        recvline[n] = '\0';
        fputs(recvline, stdout);
    }
}