/**
 * 试着编写一个程序，其功能是每次一页地显示已产生的输出。
 * 使用技术：
 *  无名管道pipe
 *  fork
 *  dup2
*/

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEF_PAGER "/bin/more"   /*默认的分页程序*/
#define MAXLINE 1024

int main(int argc, char* argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char *pager, *argv0;
    char line[MAXLINE];
    FILE *fp;

    if(argc != 2)
    {
        printf("usage: a.out <pathname>");
        return -1;
    }

    if((fp = fopen(argv[1], "r")) == NULL) {
        printf("can't open %s", argv[1]);
        return -1;
    }
    if(pipe(fd) < 0) {
        printf("pipe error\n");
        return -1;
    }

    if((pid = fork()) < 0) {
        printf("fork error\n");
        return -1;
    } else if(pid > 0) {
        close(fd[0]);

        while(fgets(line, MAXLINE, fp) != NULL) {
            n = strlen(line);
            if(write(fd[1], line, n) != n) {
                printf("write error to pipe\n");
                return -1;
            }
        }

        if(ferror(fp)) {
            printf("fgets error\n");
            return -1;
        }
        close(fd[1]);

        if(waitpid(pid, NULL, 0) < 0) {
            printf("waitpid error\n");
            return -1;
        }
        exit(0);
    } else {
        close(fd[1]);
        if(fd[0] != STDIN_FILENO) {
            if(dup2(fd[0], STDIN_FILENO) != STDIN_FILENO) {
                printf("dup2 error\n");
                return -1;
            }
            close(fd[0]);
        }
        if((pager = getenv("PAGER")) == NULL)
            pager = DEF_PAGER;
        if((argv0 = strrchr(pager, '/')) != NULL) //找到最后一个'/'所在位置指针
            argv0++;
        else 
            argv0 = pager;

        if(execl(pager, argv0, (char*)0) < 0) {
            printf("execl error for %s\n", pager);
            return -1;
        }
    }
    exit(0);    
}