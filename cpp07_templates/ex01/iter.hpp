#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F> void iter(T *array, const int size, F func) {
    for (int i = 0; i < size; i++) {
        func(array[i]);
    }
}

#endif