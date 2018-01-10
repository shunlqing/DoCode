/**
 * sock.h
 * 包含套接字使用的头文件
*/
#ifndef _SOCK_H_
#define _SOCK_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h> //inet_pton
#include <errno.h>
#include <signal.h>
#include <strings.h>
#include <string.h>


#define MAXLINE 4096

#endif