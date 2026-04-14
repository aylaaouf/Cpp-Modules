#include "iter.hpp"

template <typename T>
void print(const T& x) {
    std::cout << x << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, sizeof(arr) / sizeof(arr[0]), print<int>);
    std::string str[] = {"one", "two", "three"};
    iter(str, sizeof(str) / sizeof(str[0]), print<std::string>);
}