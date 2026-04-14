#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T> class Array {
    private:
        T* data;
        unsigned int s;
    public:
        Array() : data(NULL), s(0) {}
        Array(unsigned int n) : data(new T[n]()), s(n) {}
        Array(const Array& other) {
            s = other.s;
            data = new T[s]();
            for (unsigned int i = 0; i < s; i++) {
                data[i] = other.data[i];
            }
        }
        Array<T>& operator=(const Array& other) {
            if (this != &other) {
                delete[] data;
            s = other.s;
            data = new T[s]();
            for (unsigned int i = 0; i < s; i++)
                    data[i] = other.data[i];
            }
            return *this;
        }
        ~Array() {
            delete[] data;
        }
        T& operator[](unsigned int i)
        {
            if (i >= s)
                throw std::out_of_range("Array index is out of bounds");
            return data[i];
        }
        unsigned int size() {
            return (s);
        }
};

#endif