/**
 * 剑指Offer 题10
 * 题目：求菲波那契数列的第n项
 *     写一个函数，输入n,求Fibonacci数列的第n项。
 * 
 * 青蛙跳台阶问题可以用这种解法。
*/

#include <iostream>
using namespace std;

/**
 * 效率非常低的做法
 * 对同一个n，多次调用
*/
long long Fibonacci_slow(unsigned int n)
{
    if(n <= 0) {
        return 0;
    }

    if(n == 1) {
        return 1;
    }

    return Fibonacci_slow(n - 1) + Fibonacci_slow(n - 2);
}

/**
 * 从下往上算
*/
long long Fibonacci_fast(unsigned int n)
{
    long long f0 = 0, f1 = 1;
    long long fx, fxPre, fCur;

    if(n == 0)
        return f0;
    
    if(n == 1)
        return f1;
    
    fxPre = f0;
    fx = f1;

    int i = 2;
    while(i <= n)
    {
        fCur = fxPre + fx;
        fxPre = fx;
        fx = fCur;
        i++;
    }

    return fCur;
}


int main()
{
    cout << Fibonacci_slow(13) << endl;
    cout << Fibonacci_fast(13) << endl;
}