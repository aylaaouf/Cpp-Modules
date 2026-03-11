#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Intern someIntern;

    AForm* f1 = someIntern.makeForm("shrubbery creation", "Home");
    AForm* f2 = someIntern.makeForm("robotomy request", "Bender");
    AForm* f3 = someIntern.makeForm("presidential pardon", "Ford Prefect");
    AForm* f4 = someIntern.makeForm("unknown form", "Nothing");

    if (f1) std::cout << "Created form: " << f1->getName() << std::endl;
    if (f2) std::cout << "Created form: " << f2->getName() << std::endl;
    if (f3) std::cout << "Created form: " << f3->getName() << std::endl;
    if (!f4) std::cout << "Form not created for unknown form." << std::endl;

    delete f1;
    delete f2;
    delete f3;

    return 0;
}