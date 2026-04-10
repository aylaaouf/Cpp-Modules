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

void ScalarConverter::convert(const std::string &input)
{
    std::string type = checkInput(input);

    if (type == "special")
    {
        double d = std::strtod(input.c_str(), NULL);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << d << "f\n";
        std::cout << "double: " << d << "\n";
        return;
    }
    if (type == "char")
    {
        char c = input[0];
        std::cout << "char: " << c << "\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return;
    }
    if (type == "int")
    {
        char *end;
        long l = std::strtol(input.c_str(), &end, 10);
        if (*end != '\0' || l > INT_MAX || l < INT_MIN)
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
        int i = static_cast<int>(l);
        if (i >= 0 && i <= 127 && isprint(i))
            std::cout << "char: '" << static_cast<char>(i) << "'\n";
        else if (i >= 0 && i <= 127)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";

        std::cout << "int: " << i << "\n";
        std::cout << "float: " << static_cast<float>(i) << ".0f\n";
        std::cout << "double: " << static_cast<double>(i) << ".0\n";
        return;
    }
    if (type == "float" || type == "double")
    {
        char *end;
        double d = std::strtod(input.c_str(), &end);
        if (*end != '\0' && *end != 'f')
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
        int i = static_cast<int>(d);
        float f = static_cast<float>(d);
        if (d >= 0 && d <= 127 && isprint(i))
            std::cout << "char: '" << static_cast<char>(i) << "'\n";
        else if (d >= 0 && d <= 127)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        if (d > INT_MAX || d < INT_MIN || std::isnan(d))
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << i << "\n";
        if (f == i)
        {
            std::cout << "float: " << f << ".0f\n";
            std::cout << "double: " << d << ".0\n";
        }
        else
        {
            std::cout << "float: " << f << "f\n";
            std::cout << "double: " << d << "\n";
        }
        return;
    }
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}
