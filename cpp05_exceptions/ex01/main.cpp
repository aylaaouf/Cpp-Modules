#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat a("Figo", 10);
        Bureaucrat b("draganov", 100);

        Form f1("Featiring", 20, 5);
        Form f2("Clash", 120, 50);

        std::cout << "---- Test 1: Strong bureaucrat ----" << std::endl;
        a.signForm(f1);

        std::cout << "---- Test 2: Weak bureaucrat ----" << std::endl;
        b.signForm(f1);

        std::cout << "---- Test 3: Another form ----" << std::endl;
        b.signForm(f2);

        std::cout << "---- Test 4: Already signed ----" << std::endl;
        a.signForm(f1);
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;        
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}