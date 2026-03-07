#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    protected:
        void checkExecute(Bureaucrat const & executor) const;
    public:
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const = 0;
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
        class FormNotSignedException : public std::exception
        {
        public:
            const char* what() const throw()
            {
                return "Form is not signed";
            }
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif