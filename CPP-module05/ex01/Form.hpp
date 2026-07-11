#ifndef FORM_HPP
#define FORM_HPP

#define SAGE_GREEN  "\033[38;2;163;177;138m"
#define DUSTY_BLUE  "\033[38;2;109;130;153m"
#define SOFT_PURPLE "\033[38;2;150;120;170m"
#define RESET       "\033[0m"

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExecute;

public:
    Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
    Form(const Form &copy);
    Form &operator=(const Form &other);
    ~Form();

    const std::string &getName() const;
    bool              getSigned() const;
    int               getGradeToSign() const;
    int               getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif