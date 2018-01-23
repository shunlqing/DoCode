/**
 * 编写一个程序，将输入字符串中的字符按如下规则排序。
 * 规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
 *     如，输入： Type   输出： epTy
 * 规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
 *   如，输入： BabA   输出： aABb
 * 规则 3 ：非英文字母的其它字符保持原来的位置。
 *   如，输入： By?e   输出： Be?y
 * 样例：
 *  输入：
 * A Famous Saying: Much Ado About Nothing(2012/8).
 *  输出：
 * A  aaAAbc   dFgghh :  iimM   nNn   oooos   Sttuuuy  (2012/8).
*/
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    void sort(string& str)
    {
        int sz = str.size()-1;
        for(; sz > 0; sz--) {
            if(!islower(str[sz]) && !isupper(str[sz]))
                continue;
            
            int j = 0;
            for(int i = 0; i <= sz; i++) {
                if(!islower(str[i]) && !isupper(str[i]))
                    continue;
                j = i+1;
                if(j > sz)
                    break;
                while(!islower(str[j]) && !isupper(str[j]))
                    j++;
                
                if(j > sz)
                    break;

                if(less(str[j], str[i]))
                    exch(str, i, j);
            }
        }
    }

    bool less(char a, char b)
    {
        char alower = tolower(a);
        char blower = tolower(b);
        return alower < blower;
    }

    void exch(string& str, int i, int j)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
};

int main()
{
    Solution s;

    string str;
    while(getline(cin, str)) {
        s.sort(str);
        cout << str << endl;
    }
}

/**
 * 
*/