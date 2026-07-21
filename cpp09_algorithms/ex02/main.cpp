#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe algo;
    if (ac < 2)
        return 1;
    if (!algo.readData(ac, av))
    {
        std::cerr << "Invalid character in argv" << std::endl;
        return 1;
    }
    algo.Sort();
    return 0;
}