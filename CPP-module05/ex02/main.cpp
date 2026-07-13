#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur");

	boss.signForm(shrub);
	boss.executeForm(shrub);

	boss.signForm(robot);
	boss.executeForm(robot);

	boss.signForm(pardon);
	boss.executeForm(pardon);

	return 0;
}