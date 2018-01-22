/**
 *  插入排序
*/
#ifndef _INSERTION_H_
#define _INSERTION_H_

#include <iostream>
#include "BaseSort.h"

template <typename Comparable>
class Insertion : public BaseSort<Comparable> {
public:
    void sort(Comparable a[], int size)
    {
        for(int i = 1; i < size; i++) {
            for(int j = i; j > 0 && this->less(a[j], a[j-1]); j--) { // 使用this显示类的依赖
                this->exch(a, j, j - 1); 
            }
        }
    }
};

#endif