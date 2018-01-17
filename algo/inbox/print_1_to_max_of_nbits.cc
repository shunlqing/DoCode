#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

bool Increase(char * str)
{
    int len = strlen(str);
    int index = len;
    bool c = false;
    while(index >= 0){
        if((str[index] + 1) <= '9'){
            *(str + index) = *(str + index) + 1;
            printf("%s\n", str);
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

    printf("%s\n", buf);
    Increase(buf);
    printf("%s\n", buf);
    // while(Increase(buf))
    // {
    //     printf("%s\n", buf);
    // }
}

int main()
{
    print1ToMaxOfNDigits(3);
}