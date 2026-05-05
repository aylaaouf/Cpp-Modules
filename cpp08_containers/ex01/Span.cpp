#include "Span.hpp"

Span::Span(unsigned int num) : N(num) {}

void Span::addNumber(int number) {
    if (container.size() >= N)
        throw std::runtime_error("Span is full");
    container.push_back(number);
}

int Span::shortestSpan() {
    if (container.size() < 2)
        throw std::runtime_error("Not enough numbers");
    std::vector<int> tmp = container;
    std::sort(tmp.begin(), tmp.end());
    int diff;
    int min = INT_MAX;
    for (std::vector<int>::iterator it = tmp.begin(); it + 1 != tmp.end(); it++) {
        diff = *(it + 1) - *it;
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan() {
    if (container.size() < 2)
        throw std::runtime_error("Not enough numbers");
    int min = *std::min_element(container.begin(), container.end());
    int max = *std::max_element(container.begin(), container.end());
    return (max - min);
}

void Span::addNumber(int *numbers, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (container.size() >= N)
            throw std::runtime_error("Span is full");
        container.push_back(numbers[i]);
    }
}