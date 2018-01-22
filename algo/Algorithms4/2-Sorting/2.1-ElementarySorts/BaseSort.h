#ifndef _BASESORT_H_
#define _BASESORT_H_

#include <iostream>
#include <assert.h>

template <typename Comparable>
class BaseSort {
public:
    virtual void sort(Comparable a[], int size) = 0;

    bool less(Comparable v, Comparable w) const
    {
        return v < w;
    }

    void exch(Comparable a[], int i, int j)
    {
        /*交换位置*/
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    void show(Comparable a[], int size) const
    {
        /*打印函数*/
        for(int i = 0; i < size; i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;
    }

    bool isSorted(Comparable a[], int size) const
    {
        /*测试数组元素是否有序*/
        for(int i = 1; i < size; i++)
            if(less(a[i], a[i - 1])) return false;
        return true;
    }

    /*Java可以在类内设置一个用例main，C++我们定义一个test用例*/
    void test(Comparable a[], int size)
    {
        sort(a, size);
        assert(isSorted(a, size));
        show(a, size);
    }
};

#endif