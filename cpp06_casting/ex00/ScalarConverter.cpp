#include "ScalarConverter.hpp"

std::string checkInput(const std::string &input) {
     if (input == "nan" || input == "nanf" ||
        input == "+inf" || input == "-inf" ||
        input == "+inff" || input == "-inff")
        return "special";

    if (input.length() == 1 && !isdigit(input[0]))
        return "char";

    int i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;

    bool isInt = true;
    for (int j = i; j < (int)input.length(); j++)
    {
        if (!isdigit(input[j]))
            isInt = false;
    }
    if (isInt && i != (int)input.length())
        return "int";

    bool hasDot = false;
    bool hasF = false;
    i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;

    for (int j = i; j < (int)input.length(); j++)
    {
        if (input[j] == '.')
        {
            if (hasDot)
                return "invalid";
            hasDot = true;
        }
        else if (input[j] == 'f' && j == (int)input.length() - 1)
            hasF = true;
        else if (!isdigit(input[j]))
            return "invalid";
    }

    if (hasDot && hasF)
        return "float";

    if (hasDot && !hasF)
        return "double";

    return "invalid";
}

void ScalarConverter::convert(const std::string &input) {
    std::string inputType = checkInput(input);
    // if (inputType )
    double d = std::stod(input);
}