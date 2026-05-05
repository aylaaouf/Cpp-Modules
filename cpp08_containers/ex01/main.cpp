#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    try {
        Span sp = Span(100);
        int arr[] = {7, 30, 1};
        sp.addNumber(42);
        sp.addNumber(-5);
        sp.addNumber(18);
        sp.addNumber(3);
        sp.addNumber(99);
        sp.addNumber(12);
        sp.addNumber(-20);
        sp.addNumber(arr, 3);
        for (int i = 0; i < 90; i++) {
            sp.addNumber(rand() % 1000);
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}