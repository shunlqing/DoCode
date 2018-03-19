/**
 * 最长上升子序列的长度
*/

/**
 * 动态规划
*/

#include <iostream>
#include <vector>

using namespace std;

class AscentSequence {
public:
    int findLongest(vector<int> A, int n) {
        // write code here
        vector<int> dp(A.size(), 0);
        int Max = 0;

        for(int i = 0; i < A.size(); i++)
        {
            Max = 0;
            for(int j = 0; j < i; j++)
            {
                if(A[j] < A[i])
                    Max = max(Max, dp[j]);
            }
            dp[i] = Max + 1;
        }

        Max = 0;
        for(int i = 0; i < A.size(); i++)
        {
            Max = max(Max, dp[i]);
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
    vector<int> a = {2,1,4,3,1,5,6};
    AscentSequence as;
    cout << as.findLongest(a, a.size()) << endl;
}
