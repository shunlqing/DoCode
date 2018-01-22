/**
 * 排序算法类的模板
*/
#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_
#include <iostream>
#include <string>

template <typename Comparable>
class Example{
public:
    void sort(Comparable a[], int size)
    {
        /*每个排序算法实现*/
    }

    bool less(Comparable v, Comparable w) const
    {
        /*比较函数， 数据类型需要是可比较的，即可以为实现<操作符重载*/
        /*Java: return v.compareTo(w) < 0; 数据类型实现compareTo接口*/
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

    bool isSorted(Comparable a[]) const
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