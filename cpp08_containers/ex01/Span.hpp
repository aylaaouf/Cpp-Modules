#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#include <climits>

class Span {
    private:
        unsigned int N;
        std::vector<int> container; 
    public:
        Span(unsigned int num);
        void addNumber(int number);
        void addNumber(int *numbers, unsigned int size);
        int shortestSpan();
        int longestSpan();
};

#endif