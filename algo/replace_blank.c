/**
 * 来源: 剑指Offer
 * 题目: 请实现一个函数,把字符串中的每个空格替换成"%20".
 * shunlqing@163.com
*/

#include <string.h>
#include <stdio.h>

/**
 * 两种方式: 
 *      在原来的字符串上修改(保证字符串的空间足够)
 *      重新申请字符串空间
*/

/**
 * 假设字符串原有空间足够:
 *      先扫描一遍, 统计空格数目count;
 *      利用count确定新的字符串'\0'的位置;
 *      从字符串尾部开始调整字符串.
 *      时间复杂度为O(n)
 * 
 * 为了安全起见,我们要求输入容量length
*/

static void ReplaceBlank(char * str, int length)
{
    int str_len;
    int blank_cnt = 0;
    char * p = str;
    char * p1;

    /*边界1: 输入字符串指针为NULL*/
    /**/
    if(str == NULL || length <= 0)
        return;

    str_len = strlen(str);

    while(*p != '\0')
    {
        if(*p == ' ')
            blank_cnt++;
        ++p;
    }

    if(blank_cnt == 0 || length < (str_len + 2 * blank_cnt + 1))
        return;


    p1 = p + 2 * blank_cnt;
    *p1-- = '\0';
    --p;

    while(p != str)
    {
        if(*p == ' ')
        {
            *p1-- = '0';
            *p1-- = '2';
            *p1-- = '%';
            p--;
        } else {
            *p1-- = *p--;
        }
    }
    if(*p == ' ')
    {
        *p1-- = '0';
        *p1-- = '2';
        *p1-- = '%';
    }
}

static inline void test(char str[], int length)
{
    printf("Input: %s, strlen: %d\n", str, (int)strlen(str));
    ReplaceBlank(str, length);
    printf("Output: %s, strlen: %d\n", str, (int)strlen(str));
}

int main()
{
    char str[100] = "Sh un l qing 's Blog"; //正常案例
    char str1[100] = " shunl"; //空格在字符串最前面
    char str2[100] = "shunlqing "; //空格在字符串最后面
    char str3[21] = "shun    ling"; //连续空格
    char str4[100] = "shunlqing";//没有空格

    printf("Testing...\n");
    
    test(str, sizeof(str));
    test(str1, sizeof(str1));
    test(str2, sizeof(str2));
    test(str3, sizeof(str3));
    test(str4, sizeof(str4));

    printf("Testing End\n");
}