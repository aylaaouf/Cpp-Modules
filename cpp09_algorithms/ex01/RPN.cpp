#include "RPN.hpp"

bool allowed_char(char c) {
    char allowed[] = {'+', '-', '/', '*', ' '};

    for (int i = 0; i <= 4; i++)
    {
        if (allowed[i] == c)
            return true;
    }
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

int rpn(std::string argv, std::vector<int> &data) {
    int i = 0;
    while (argv[i])
    {
        if (!allowed_char(argv[i]))
            return 0;
        i++;
    }
    return 1;
}