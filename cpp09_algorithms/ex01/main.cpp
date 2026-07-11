#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2)
        return 1;
    std::vector<int> data;
    if (!rpn(av[1], data))
    {
        std::cerr << "Character not allowed in argv" << std::endl;
        return 1;
    }
    return 0;
}