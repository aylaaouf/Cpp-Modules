#include "RPN.hpp"

bool allowed_char(char c) {
    char allowed[] = {'+', '-', '/', '*'};

    for (int i = 0; i < 4; i++)
    {
        if (allowed[i] == c)
            return true;
    }
    return false;
}

bool calcul(std::vector<int> &data, char op)
{
    int result = 0;
    int right = data.back();
    data.pop_back();
    int left = data.back();
    data.pop_back();

    switch(op)
    {
        case '+':
            result = left + right;
            break ;
        case '-':
            result = left - right;
            break ;
        case '/':
            if (right != 0)
                result = left / right;
            else
                return false;
            break ;
        case '*':
            result = left * right;
            break ;
    }
    data.push_back(result);
    return true;
}

int rpn(std::string argv, std::vector<int> &data) {
    int i = 0;
    while (argv[i])
    {
        if (argv[i] == ' ')
        {
            i++;
            continue;
        }
        if (!allowed_char(argv[i]) && !std::isdigit(argv[i]))
            return 0;
        if (std::isdigit(argv[i]))
            data.push_back(argv[i] - '0');
        else
        {
            if (data.size() < 2)
                return 0;
            if (!calcul(data, argv[i]))
                return 0;
        }
        i++;
    }
    if (data.size() != 1)
        return 0;
    else
        std::cout << data.back() << std::endl;
    return 1;
}