#ifndef SCOLARCONVERTER_HPP
#define SCOLARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>

class ScalarConverter {
    public:
        static void convert(std::string const &input);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);
        ~ScalarConverter();
};

void checkInput(std::string &input);

#endif