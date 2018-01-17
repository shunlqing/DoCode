#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

bool Increase(char * str)
{
    int len = strlen(str);
    int index = len - 1;
    bool c = false;
    while(index >= 0){
        if((str[index] + 1) <= '9'){
            *(str + index) = *(str + index) + 1;
            c = false;
            break;
        } else {
            str[index] = '0';
            c = true;
            index--;
        }
    }

    if(index >= 0)
        return true;
    else 
        return false;
}

void print1ToMaxOfNDigits(int n)
{
    if(n <= 0){
        printf("n should be > 0\n");
        return;
    }

    char *buf = new char(sizeof(char) * n + 1);
    memset(buf, '0', n+1);
    buf[n] = '\0';

    while(Increase(buf))
    {
        printf("%s\t", buf);
    }
}

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("usage: %s <n>\n", argv[0]);
        return -1;
    }
    print1ToMaxOfNDigits(atoi(argv[1]));
    // char *pBuf = new char(sizeof(char)*3 + 1);
    // memset(pBuf, '0', 3+1);
    // *(pBuf + 3) = '\0';

    // printf("%s\n", pBuf);

    // *(pBuf + 2) = '1';

    // printf("%s\n", pBuf);
}