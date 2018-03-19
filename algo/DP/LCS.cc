/**
 * 最长公共子序列的长度
*/

/**
 * 动态规划
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
        int dp[n+1][m+1];
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                dp[i][j] = 0;
            }
        }

        int Max = 0;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 || j == 0)
                {
                    cout << "a" << endl;
                    dp[i][j] = 0;
                } 
                else if(i > 0 && j > 0 && A[i-1] == B[j-1])
                {
                    cout << "b" << " " << i <<  " " << j << endl;
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    cout << "c" << endl;
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

                Max = max(Max, dp[i][j]);
            }
        }

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }

        return Max;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
};

int main()
{
    string a = "rsymsknwbiapzhuoeyhjubogitoqfkswhbqhwqzyjuvdlzjlhlaubecnkzgvurdsuvqghpjazgxvue";
    string b = "sclzdzbtrrkdybusjyjrszzqaebkpdtqnqadndvkenqirqqsplmceuuzhukcxxnkcyyvucqjlkysfarxkulpayvtwfmfaqpikzdslpklomafvtesecxygahwnyljldutzsoywiwkugerfbfefcqfvcrzcvbevufzbkbhfeshhdasqo";
    LCS lcs;
    cout << lcs.findLCS(a, a.size(), b, b.size()) << endl;

    string c = "z";//ynnqufc";
    string d = "d";//dbauhkw";
    cout << lcs.findLCS(c, c.size(), d, d.size()) << endl;
}