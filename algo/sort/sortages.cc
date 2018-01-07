/**
 * 为公司的员工年龄排序, 能使用常量内存空间,不得超过O(n)
 * 特点:
 *      年龄的范围有限,设置timesOfAges[100]
*/

#include <iostream>
using namespace std;

void SortAges(int ages[], int length)
{
    if(ages == nullptr || length <= 0)
        return;

    unsigned int timesOfAges[100] = {0};
    for(int i = 0; i < length; i++)
    {
        timesOfAges[ages[i] - 1]++;
    }

    int index = 0, i = 0;
    while(index < 100 && i < length)
    {
        while(timesOfAges[index] > 0)
        {
            ages[i++] = index + 1;
            timesOfAges[index]--;
        }
        index++;
    } //end of while
    /*两次while循环,为什么是O(n), 因为总执行次数总是length*/
}

int main()
{
    int data[] = {1, 3, 66, 33, 22, 34, 10, 78, 37, 49, 27, 89, 34, 23, 45, 54, 56, 34, 33, 66};

    SortAges(data, 20);

    for(int i = 0; i < 20; i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}