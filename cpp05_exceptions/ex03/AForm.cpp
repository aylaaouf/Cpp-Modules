#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("default"),
      isSigned(false),
      gradeToSign(150),
      gradeToExecute(150) { }

AForm::AForm(const std::string& name, int gradeSign, int gradeExec)
    : name(name),
      isSigned(false),
      gradeToSign(gradeSign),
      gradeToExecute(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) { }

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() { }

std::string AForm::getName() const {
    return (name);
}

bool AForm::getIsSigned() const {
    return (isSigned);
}

int AForm::getGradeToSign() const {
    return (gradeToSign);
}

int AForm::getGradeToExecute() const {
    return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    if (isSigned)
        throw AlreadySignedException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "Form name: " << f.getName() << std::endl;
    out << "Signed: " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
    out << "Grade to sign: " << f.getGradeToSign() << std::endl;
    out << "Grade to execute: " << f.getGradeToExecute();

    return out;
}

void AForm::checkExecute(Bureaucrat const & executor) const
{
    if (!isSigned)
        throw FormNotSignedException();

    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}
