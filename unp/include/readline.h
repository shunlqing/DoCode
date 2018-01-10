#ifndef _READLINE_H_
#define _READLINE_H_

ssize_t Readline(int fd, void *ptr, size_t maxlen);
ssize_t readline(int fd, void *vptr, size_t maxlen);
ssize_t readlinebuf(void **vptrptr);

#endif
