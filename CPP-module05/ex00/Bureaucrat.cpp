#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) 
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() { }

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}


const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}