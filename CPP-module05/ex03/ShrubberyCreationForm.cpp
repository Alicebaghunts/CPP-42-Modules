#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy), _target(copy._target) { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream myFile((_target + "_shrubbery").c_str());

	if (!myFile)
	{
		std::cout << "Cannot create file" << std::endl;
		return ;
	}

	myFile << "             .::::::::." << std::endl;
	myFile << "          .::'        '::." << std::endl;
	myFile << "        .::               ::." << std::endl;
	myFile << "       ::    :::           ::" << std::endl;
	myFile << "       ::            ::::   ::" << std::endl;
	myFile << "        '::    ...         ::'" << std::endl;
	myFile << "          '::.         .::'" << std::endl;
	myFile << "             ':::::::::'" << std::endl;
	myFile << "                 |||" << std::endl;
	myFile << "                 |||" << std::endl;
	myFile << "                _|||_" << std::endl;

	myFile.close();

	std::cout << "\033[38;2;163;177;138m";
	std::cout << "Shrubbery file created: " << _target << "_shrubbery";
	std::cout << "\033[0m" << std::endl;
}