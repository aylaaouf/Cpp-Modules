#pragma once

#include <cctype>
#include <utility>
#include <vector>
#include <iostream>
#include <cstdlib>

class PmergeMe {
    private:
        std::vector<int> _numbers;
    public:
        int readData(int ac, char **av);
        void makePairs(std::vector<int> &numbers,
                    std::vector<std::pair<int, int> > &pairs,
                    std::vector<int> &main,
                    std::vector<int> &pending,
                    bool &hasOdd,
                    int &odd);
        void recursiveSort(std::vector<int> &chain);
        void Sort();
        void insertElements(std::vector<int> &main, std::vector<std::pair<int, int> > &pairs);
        int binarysearch(std::vector<int> &mainChain, int value);
        int binarysearch(std::vector<int> &mainChain, int value, int limit);
};