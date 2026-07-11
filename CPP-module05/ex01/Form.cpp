#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string &name, const int gradeToSign,
	const int gradeToExecute) : _name(name), _signed(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToExecute < 1 || _gradeToSign < 1)
	{
		throw GradeTooHighException();
	}
	if (_gradeToSign > 150 || _gradeToExecute > 150)
	{
		throw GradeTooLowException();
	}
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", signed: " << form.getSigned()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return os;
}
