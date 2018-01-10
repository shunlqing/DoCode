/**
 * 包裹函数
*/

#include "sock.h"
#include "error.h"

ssize_t Write(int fd, const void *buf, size_t count)
{
    int writelen;
    if((writelen = write(fd, buf, count)) < 0) {
        err_sys("write error");
    }

    return writelen;
}

ssize_t Read(int fd, void *buf, size_t count)
{
    int readlen;
    if((readlen = read(fd, buf, count)) < 0) {
        err_sys("read error");
    }

    return readlen;
}

int Close(int fd)
{
    int ret;
    if((ret = close(fd)) != 0) {
        err_sys("close error");
    }

    return ret;
}

int Fputs(const char *s, FILE* stream)
{
    int ret;
    if((ret = fputs(s, stream)) == EOF)
        err_sys("fputs error");

    return ret;
}

char* Fgets(char* s, int size, FILE* stream)
{
    char *rptr;
    if((rptr = fgets(s, size, stream)) == NULL && ferror(stream)) {
        err_sys("fgets error");
    }

    return rptr;
}

/**
 * socket相关
*/
int Socket(int domain, int type, int protocol)
{
    int fd;
    if((fd = socket(domain, type, protocol)) == -1) {
        err_sys("socket error");
    }

    return fd;
}

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret;
    if((ret = bind(sockfd, addr, addrlen)) == -1) {
        err_sys("bind error");
    }

    return ret;
}

int Accept(int sockfd, struct sockaddr* addr, socklen_t *addrlen)
{
    int retfd;

again:
    if((retfd = accept(sockfd, addr, addrlen)) == -1) {
        if(errno == EINTR) {
            goto again;
        } else {
            err_sys("accept error");
        }
    }

    return retfd;
}

int Listen(int sockfd, int backlog)
{
    int ret;
    if((ret = listen(sockfd, backlog)) == -1) {
        err_sys("listen error");
    }

    return ret;
}

int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret;
    if((ret = connect(sockfd, addr, addrlen)) == -1) {
        err_sys("connect error");
    }

    return ret;
}

const char *
Inet_ntop(int family, const void *addrptr, char *strptr, size_t len)
{
        const char      *ptr;

        if (strptr == NULL)             /* check for old code */
                err_quit("NULL 3rd argument to inet_ntop");
        if ( (ptr = inet_ntop(family, addrptr, strptr, len)) == NULL)
                err_sys("inet_ntop error");             /* sets errno */
        return(ptr);
}

void
Inet_pton(int family, const char *strptr, void *addrptr)
{
        int             n;

        if ( (n = inet_pton(family, strptr, addrptr)) < 0)
                err_sys("inet_pton error");      /* errno set */
        else if (n == 0)
                err_quit("inet_pton error");     /* errno not set */

        /* nothing to return */
}

ssize_t Recvfrom(int sockfd, void *buff, size_t nbytes, int flags, struct sockaddr *from, socklen_t *addrlen)
{
    int readlen;
    if((readlen = recvfrom(sockfd, buff, nbytes, flags, from, addrlen)) < 0) {
        err_sys("recvfrom error");
    }

    return readlen;
}

ssize_t Sendto(int sockfd, const void *buff, size_t nbytes, int flags, const struct sockaddr *to, socklen_t addrlen)
{
    int writelen;
    if((writelen = sendto(sockfd, buff, nbytes, flags, to, addrlen)) < 0) {
        err_sys("sendto error");
    }

    return writelen;
}