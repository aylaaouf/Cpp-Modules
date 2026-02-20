#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);
        ~Bureaucrat();
        class GradeTooHighException : public std::exception {
            const char* what() const throw() {
                return "Grade too high!";
            }
        };
        class GradeTooLowException : public std::exception {
            const char* what() const throw() {
                return "Grade too Low!";
            }
        };
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
    };

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
    
#endif