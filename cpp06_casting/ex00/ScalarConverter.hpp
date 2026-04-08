#ifndef SCOLARCONVERTER_HPP
#define SCOLARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

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