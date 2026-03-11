#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() { }

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) { }
    return *this;
}

Intern::~Intern() { }

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    int index = -1;
    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            index = i;
            break ;
        }
    }
    switch (index)
    {
        case 0: return new ShrubberyCreationForm(target);
        case 1: return new RobotomyRequestForm(target);
        case 2: return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern couldn't find the form" << std::endl;
    }
    return NULL;
}