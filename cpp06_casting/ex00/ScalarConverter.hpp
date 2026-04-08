#ifndef SCOLARCONVERTER_HPP
#define SCOLARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
    public:
        static void convert(std::string const &input);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);
        ~ScalarConverter();
};

void checkinput(std::string &input);

#endif