/**
 * 最长公共子串 
*/

#include <iostream>
using namespace std;

class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        // write code here
        int dp[n][m];
        int Max = 0;
        
        if(n == 0 || m == 0)
            return 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(A[i] == B[j]) {
                    if(i > 0 && j > 0 && A[i-1] == B[j-1])
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else 
                        dp[i][j] = 1;
                } else {
                        dp[i][j] = 0;
                }
                Max = max(Max, dp[i][j]);
            }
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
    string a = "abcbaaabbbaabacabababcacbcabbbcccaaccabbbabcbbbcbcbaaabcaacbcacabaaacbccaaccccbbaccaaabcaaaababacababcaabcaabccbaacabbbacaabacabccccbababbb";
    string b = "ccbbcacccaaabcacbacacabbccacaaccbacabcabacabaaaaccacbbccabcaaacbaabcbaaabbabccaccaaccccaccbbcccac";
    // string a = "aadfjfj";
    // string b = "ssdfjfj";
    LongestSubstring ls;
    cout << ls.findLongest(a, a.size(), b, b.size()) << endl;
}