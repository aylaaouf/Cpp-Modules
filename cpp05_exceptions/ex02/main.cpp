#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat ayoub("Ayoub", 50);
    Bureaucrat yassin("Yassin", 1);
    Bureaucrat amine("Amine", 150);

    ShrubberyCreationForm form1("form1");
    RobotomyRequestForm form2("form2");
    PresidentialPardonForm form3("form3");

    std::cout << "=== Signing forms ===" << std::endl;
    try {
        form1.beSigned(ayoub);
        form2.beSigned(yassin);
        form3.beSigned(amine);
    } catch (std::exception & e) {
        std::cout << "Signing error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Executing forms manually ===" << std::endl;
    try {
        form1.execute(ayoub);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        form2.execute(yassin);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        form3.execute(amine);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Executing forms via Bureaucrat::executeForm ===" << std::endl;
    ayoub.executeForm(form1);
    yassin.executeForm(form2);
    amine.executeForm(form3);

    std::cout << "\n=== Printing form status ===" << std::endl;
    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << "\n=== Signing already signed form ===" << std::endl;
    try {
        form1.beSigned(yassin);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}