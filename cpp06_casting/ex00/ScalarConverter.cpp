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
    if (inputType == "special") {
        double d = std::atof(input.c_str());
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << d << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (inputType == "char") {
        char c = input[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
    else if (inputType == "int") {
        int i = std::atoi(input.c_str());
        char c = (i >= 0 && i <= 127 && isprint(i)) ? static_cast<char>(i) : 0;
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);
        if (c)
            std::cout << "char: '" << c << "'" << std::endl;
        else if (i >= 0 && i <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
    else if (inputType == "float" || inputType == "double") {
        double d = std::atof(input.c_str());
        int i = static_cast<int>(d);
        char c = (i >= 0 && i <= 127 && isprint(i)) ? static_cast<char>(i) : 0;
        float f = static_cast<float>(d);
        if (c)
            std::cout << "char: '" << c << "'" << std::endl;
        else if (i >= 0 && i <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (d > INT_MAX || d < INT_MIN || std::isnan(d))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
}