#ifndef _HELPERFUNC_H_
#define _HELPERFUNC_H_

void Writen(int fd, const void* vptr, size_t n);
ssize_t Readn(int fd, void* vptr, size_t n);

ssize_t writen(int fd, const void* vptr, size_t n);
ssize_t readn(int fd, void* vptr, size_t n);



#endif