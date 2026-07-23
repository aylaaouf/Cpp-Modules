#pragma once

#include <cctype>
#include <utility>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <deque>
#include <algorithm>

class PmergeMe {
    private:
        std::vector<int> _vector;
        std::deque<int>  _deque;
    public:
        int readData(int ac, char **av);
        void Sort();
};