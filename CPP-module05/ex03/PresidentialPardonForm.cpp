#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Pardon", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &copy)
	: AForm(copy), _target(copy._target) { }

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &other) {
	if (this != &other)
		_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << _target
			  << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}