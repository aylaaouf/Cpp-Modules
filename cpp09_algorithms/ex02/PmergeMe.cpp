#include "PmergeMe.hpp"

size_t limitOfSearch(size_t limit, size_t size)
{
    return limit > size ? size : limit;
}

int is_valid(char *av)
{
    int i = 0;
    if (av[i] == '+')
        i++;
    else if (av[i] == '-')
        return 0;
    if (av[i] == '\0')
        return 0;
    while (av[i])
    {
        if (!std::isdigit(av[i]))
            return 0;
        i++;
    }
    return 1;
}

int PmergeMe::readData(int size, char **av)
{
    for (int i = 1; i < size; i++)
    {
        int value = atoi(av[i]);
        if (std::find(_vector.begin(), _vector.end(), value) != _vector.end())
            return 0;
        if (!is_valid(av[i]))
            return 0;
        _vector.push_back(value);
        _deque.push_back(value);
    }
    return 1;
}

template<typename Container>
void makePairs(Container &numbers,
                    std::vector<std::pair<int, int> > &pairs,
                    Container &main,
                    Container &pending,
                    bool &hasOdd,
                    int &odd)
{
    for (size_t i = 0; i + 1 < numbers.size(); i += 2)
    {
        int a = numbers[i];
        int b = numbers[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    if (numbers.size() % 2)
    {
        hasOdd = true;
        odd = numbers.back();
    }
    for (size_t i = 0; i < pairs.size(); i++)
    {
        pending.push_back(pairs[i].first);
        main.push_back(pairs[i].second);
    }
}

std::vector<int> generateJacobsthal(size_t sizeOfPendind) {
    int first = 1;
    size_t second = 3;
    int value = -1;
    std::vector<int> numbers;
    while (true)
    {
        if (second >= sizeOfPendind)
            break;
        value = second + (first * 2);
        first = second;
        second = value;
        numbers.push_back(value);
    }
    return numbers;
}

template<typename Container>
int binarysearch(Container &mainChain, int value);

template<typename Container>
int binarysearch(Container &mainChain, int value, int limit);

template<typename Container>
void insertElements(Container &main, std::vector<std::pair<int, int> > &pairs);

template<typename Container>
void recursiveSort(Container &chain) {
    bool hasOdd = false;
    int odd = -1;
    if (chain.size() <= 1)
        return ;
    std::vector<std::pair<int, int> > pairs;
    Container mainChain;
    Container pendingChain;

    makePairs(chain, pairs, mainChain, pendingChain, hasOdd, odd);
    recursiveSort(mainChain);
    insertElements(mainChain, pairs);
    if (hasOdd)
    {
        int pos = binarysearch(mainChain, odd);
        mainChain.insert(mainChain.begin() + pos, odd);
    }
    chain = mainChain;
}

void PmergeMe::Sort()
{
    struct timeval start, end;

    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;

    gettimeofday(&start, NULL);
    recursiveSort(_vector);
    gettimeofday(&end, NULL);

    long vectorTime =
        (end.tv_sec - start.tv_sec) * 1000000L +
        (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    recursiveSort(_deque);
    gettimeofday(&end, NULL);

    long dequeTime =
        (end.tv_sec - start.tv_sec) * 1000000L +
        (end.tv_usec - start.tv_usec);

    std::cout << "After: ";
    for (size_t j = 0; j < _vector.size(); j++)
        std::cout << _vector[j] << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of "
            << _vector.size()
            << " elements with std::vector : "
            << vectorTime << " us"
            << std::endl;

    std::cout << "Time to process a range of "
            << _deque.size()
            << " elements with std::deque : "
            << dequeTime << " us"
            << std::endl;
}

template<typename Container>
int binarysearch(Container &mainChain, int value) {
    int low = 0;
    int high = mainChain.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mainChain[mid] == value)
            return mid;
        else if (mainChain[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

template<typename Container>
int binarysearch(Container &mainChain, int value, int limit) {
    int low = 0;
    int high = static_cast<int>(limitOfSearch(static_cast<size_t>(limit), mainChain.size()));
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (mainChain[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

std::vector<int> buildInsertionOrder(
    const std::vector<int>& jacob,
    size_t pendingSize) {
    std::vector<int> order;
    size_t previous = 0;
    for (size_t i = 0; i < jacob.size(); i++) {
        size_t current = jacob[i];
        if (current > pendingSize)
            current = pendingSize;
        for (size_t j = current; j > previous; j--)
            order.push_back(j - 1);
        if (previous == pendingSize)
            break ;
        previous = current;
    }
    if (previous < pendingSize)
    {
        for (size_t j = pendingSize; j > previous; --j)
            order.push_back(j - 1);
    }
    return order;
}

template<typename Container>
void insertElements(Container &main, std::vector<std::pair<int, int> > &pairs) {
    Container pending;
    for (size_t i = 0; i < pairs.size(); i++)
        pending.push_back(pairs[i].first);
    std::vector<int> jacob = generateJacobsthal(pending.size());
    std::vector<int> order = buildInsertionOrder(jacob, pending.size());
    for (size_t i = 0; i < order.size(); i++) {
        int partnerPos = binarysearch(main, pairs[order[i]].second);
        int pos = binarysearch(main, pending[order[i]], partnerPos);
        main.insert(main.begin() + pos, pending[order[i]]);
    }
}