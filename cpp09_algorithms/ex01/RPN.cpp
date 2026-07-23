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

bool calcul(std::stack<int> &data, char op)
{
    int result = 0;
    int right = data.top();
    data.pop();
    int left = data.top();
    data.pop();

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
    data.push(result);
    return true;
}

int rpn(std::string argv, std::stack<int> &data) {
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
            data.push(argv[i] - '0');
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
        std::cout << data.top() << std::endl;
    return 1;
}