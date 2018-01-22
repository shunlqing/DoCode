/**
 * 选择排序
*/
#ifndef _SELECTION_H_
#define _SELECTION_H_

#include <iostream>
#include <assert.h>
#include "BaseSort.h"

template <typename Comparable>
class Selection : public BaseSort<Comparable> {
public:
    virtual void sort(Comparable a[], int size)
    {
        /*每个排序算法实现*/
        for(int i = 0; i < size; i++) {
            int min = i;
            for(int j = i+1; j < size; j++) {
                if(this->less(a[j], a[min])) 
                    min = j;
            }
            this->exch(a, i, min);
        }
    }
};

#endif