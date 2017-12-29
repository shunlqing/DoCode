/**
 * 快速排序算法
*/

#include <exception>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    if(a == b)
        return;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * 在[start, end]区间随即选取某个索引值
 * 注意,返回至少是start,而不是0
*/
int RandomInRange(int start, int end)
{
    int incre;
    if(start == end)
        incre = 0;
    else {
       incre = (rand() % (end - start + 1));
    }

    return start + incre;
}

/**
 * Partition分区
 * 快速排序算法的核心
 * 注意:每次索引值从start开始,而不是从0开始
*/
int Partition(int data[], int length, int start, int end)
{
    if(data == nullptr || length  <= 0 || start < 0 || end >= length)
        throw runtime_error("paras error");

    int small = start - 1;
    int index = RandomInRange(start, end);
    swap(&data[index], &data[end]);

    for(index = start; index < end; index++)
    {
        if(data[index] < data[end])
        {
            small++;
            if(small != index)
                swap(&data[index], &data[small]);
        }
    }

    small++;
    swap(&data[end], &data[small]);

    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if(start == end)
        return;
    int index = Partition(data, length, start, end);

    if(start < index)
        QuickSort(data, length, start, index - 1);
    if(index < end)
        QuickSort(data, length, index + 1, end);
}

int main()
{
    srand((unsigned int)time(NULL));

    int data[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};
    QuickSort(data, 9, 0, 8);

    for(int i = 0; i < 9; i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}