#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form isn't signed";
}

AForm::AForm(const std::string &name, int gradeToSign,
	int gradeToExecute) : _name(name), _signed(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) { }

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm() { }

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();

	_signed = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << form.getName() << ", signed: " << form.getSigned()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return os;
}
