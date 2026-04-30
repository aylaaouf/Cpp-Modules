#include "easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> container;

    container.push_back(1);
    container.push_back(8);
    container.push_back(4);
    container.push_back(2);
    container.push_back(9);
    std::vector<int>::iterator it = easyfind(container, 9);
    if (it != container.end())
        std::cout << *it << std::endl;
    else if (it == container.end())
        std::cout << "Not found" << std::endl;
}