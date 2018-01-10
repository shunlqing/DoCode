#ifndef _WRAPSOCK_H_
#define _WRAPSOCK_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

ssize_t Write(int fd, const void *buf, size_t count);
ssize_t Read(int fd, void *buf, size_t count);
int Close(int fd);
int Fputs(const char *s, FILE* stream);
char* Fgets(char* s, int size, FILE* stream);

int Socket(int domain, int type, int protocol);
int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int Accept(int sockfd, struct sockaddr* addr, socklen_t *addrlen);
int Listen(int sockfd, int backlog);
int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

const char * Inet_ntop(int family, const void *addrptr, char *strptr, size_t len);
void Inet_pton(int family, const char *strptr, void *addrptr);

ssize_t Recvfrom(int sockfd, void *buff, size_t nbytes, int flags, struct sockaddr *from, socklen_t *addrlen);
ssize_t Sendto(int sockfd, const void *buff, size_t nbytes, int flags, const struct sockaddr *to, socklen_t addrlen);

#endif