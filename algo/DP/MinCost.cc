/**
 * 字符串转换最小代价
*/

/**
 * 对于两个字符串A和B，我们需要进行插入、删除和修改操作将A串变为B串，定义c0，c1，c2
 * 分别为三种操作的代价，请设计一个高效算法，求出将A串变为B串所需要的最少代价。
 * 给定两个字符串A和B，及它们的长度和三种操作代价，请返回将A串变为B串所需要的最小代价。
 * 保证两串长度均小于等于300，且三种代价值均小于等于100。
 * 
 * 测试样例：
 *  "abc",3,"adc",3,5,3,100
 * 返回： 8
*/

#include <iostream>
using namespace std;

class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        // write code here
        int dp[n+1][m+1];
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                dp[i][j] = 0;
            }
        }

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 && j == 0) {
                    dp[i][j] = 0;
                } else if(i == 0 && j > 0) {
                    dp[i][j] = dp[i][j-1] + c0;
                } else if(i > 0 && j == 0) {
                    dp[i][j] = dp[i-1][j] + c1;
                } else {
                    if(A[i-1] == B[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        int aCost = dp[i][j-1] + c0;

                        int bCost = dp[i-1][j] + c1;

                        int cCost = dp[i-1][j-1] + c2;

                        dp[i][j] = min(aCost, bCost, cCost);                        
                    }
  
                }
            }
        }

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                cout << dp[i][j] << "     ";
            }
            cout << endl;
        }

        return dp[n][m];
    }

    int min(int a, int b)
    {
        return (a < b) ? a : b;
    }

    int min(int a, int b, int c)
    {
        return min(a, min(b, c));
    }
};

int main()
{
    string a = "bbca";
    string b = "cabacab";
    MinCost mc;

    cout << mc.findMinCost(a, a.size(), b, b.size(), 1, 2, 7) << endl;
}