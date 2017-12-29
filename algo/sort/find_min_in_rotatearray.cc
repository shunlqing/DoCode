/**
 * 题目:旋转数组的最小数字
 *     把一个数组的最开始的若干个元素搬到数组的末尾,我们称之为数组的旋转.输入一个递增排序的数组的一个旋转,输出旋转数组的最小元素.
 *     例如,数组{3,4,5,1,2},为{1,2,3,4,5}的一个旋转, 该数组的最小数值为1.
*/

#include <exception>
#include <iostream>
using namespace std;

/**
 * 直观思路是:遍历数组一次,就能找到最小数组,但是时间复杂度为O(n)
 * 二分查找法的思路:递归实现
*/

int MinInRotate(int data[], int start, int end)
{
    if(data == nullptr || end < start)
        throw runtime_error("paras error");

    if(start == end)
        return data[start];

    if(end - start == 1)
        return (data[start] > data[end]) ? data[end] : data[start];

    int min = (end + start) / 2;

    /*容易遗漏的情况*/
    if(data[min] == data[start] && data[min] == data[end])
    {
        int minLeft = MinInRotate(data, start, min);
        int minRight = MinInRotate(data, min, start);
        return (minLeft > minRight) ? minRight : minLeft;
    }

    if(data[min] < data[start])
        return MinInRotate(data, start, min);
    
    if(data[min] >= data[start])
        return MinInRotate(data, min, end);
}

/**
 * 二分查找通过缩小查找区间,其实可以不用递归
*/
int MinInOrder(int data[], int start, int end);
int MinInRotateWithoutRecursion(int data[], int start, int end)
{
    if(data == nullptr || end < start)
        throw runtime_error("paras error");

    if(start == end)
        return data[start];

    int min = 0;
    int index1 = start, index2 = end;

    while(data[index1] >= data[index2])
    {
        if(index2 - index1 == 1) {
            min = index2;
            break;
        }

        min = (index1 + index2) / 2;

        if(data[min] == data[index1] && data[min] == data[index2]) {
            /*只能使用顺序查找*/
            return MinInOrder(data, index1, index2);
        }

        if(data[min] >= data[index1])
            index1 = min;
        else if(data[min] <= data[index2])
            index2 = min;
    }
    
    return data[min];
}

int MinInOrder(int data[], int start, int end)
{
    int result = data[start];
    for(int i = start + 1; i < end; ++i)
    {
        if(result > data[i])
            result = data[i];
    }
    return result;    
}

void PrintData(const char* str, int data[], int length)
{
    cout << str << ":";
    for(int i = 0; i < length; i++)   
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}

int main()
{
    cout << "Testing..." << endl;
    int data1[] = {1};
    PrintData("data1", data1, 1);
    cout << "min in data1:" << MinInRotate(data1, 0, 0) << endl;
    cout << "min in data1:" << MinInRotateWithoutRecursion(data1, 0, 0) << endl;

    int data2[] = {1, 0, 1, 1};
    PrintData("data2", data2, 4);
    cout << "min in data2:" << MinInRotate(data2, 0, 3) << endl;
    cout << "min in data2:" << MinInRotateWithoutRecursion(data2, 0, 3) << endl;

    int data3[] = {2,2,1,1};
    PrintData("data3", data3, 4);
    cout << "min in data3:" << MinInRotate(data3, 0, 3) << endl;
    cout << "min in data3:" << MinInRotateWithoutRecursion(data3, 0, 3) << endl;

    // cout << "min in nullptr:" << MinInRotate(nullptr, 0, 1) << endl;
}