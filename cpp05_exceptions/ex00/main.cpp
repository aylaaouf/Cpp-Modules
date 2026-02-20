#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "Test 1:" << std::endl;
    try
    {
        Bureaucrat a("Ayoub", 2);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << "After increment: " << a << std::endl;
        a.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Test 2:" << std::endl;
    try
    {
        Bureaucrat b("Amine", 149);
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;
        b.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Test 3:" << std::endl;
    try
    {
        Bureaucrat c("Yassin", 99);
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << "After decrement: " << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}