#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define SERV_PORT 9999

typedef struct sockaddr SA;

void err_quit(const char* errstr);
inline void err_quit(const char* errstr)
{
    fputs(errstr, stdout);
    exit(-1);
}