#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        Form();
        Form(const std::string& name, int gradeSign, int gradeExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw() {
                return "Grade too high!";
            }
        };
        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw() {
                return "Grade too Low!";
            }
        };
        class AlreadySignedException : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return "Form is already signed";
            }
        };
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif