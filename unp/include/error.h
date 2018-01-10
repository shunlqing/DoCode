#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdio.h>
#include <stdlib.h>

static inline void err_sys(const char* errStr);
static inline void err_quit(const char* errStr);

static inline void err_sys(const char* errStr)
{
    fputs(errStr, stdout);
    exit(-1);
}

static inline void err_quit(const char* errStr)
{
    fputs(errStr, stdout);
    exit(-1);
}

#endif