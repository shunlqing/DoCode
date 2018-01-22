#ifndef _SHELL_H_
#define _SHELL_H_

#include <iostream>
#include "BaseSort.h"

template <typename Comparable>
class Shell : public BaseSort<Comparable> {
public:
    virtual void sort(Comparable a[], int size)
    {
        int h = 1;
        while(h < size/3)
            h = 3*h + 1;
        while(h >= 1){
            for(int i = h; i < size; i++) {
                for(int j = i; j >= h && this->less(a[j], a[j - h]); j -= h)
                {
                    this->exch(a, j, j-1);
                }
            }
            h /= 3;
        }
    }
    // virtual void sort(Comparable a[], int size)
    // {
    //     int h = 0;
    //     while(h <= size)
    //         h = 3*h + 1;
    //     while(h >= 1){
    //         for(int i = 0; i < h; i++) {
    //             for(int j = i + h; j < size; j += h) {
    //                 for(int k = j; k > h && this->less(a[k], a[k - 1]); k--)
    //                     this->exch(a, a[k], a[k - 1]);
    //             }
    //         }
    //         h /= 3;
    //     }
    // }
};

#endif