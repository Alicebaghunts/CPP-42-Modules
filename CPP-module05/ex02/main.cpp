#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define SAGE_GREEN  "\033[38;2;163;177;138m"
#define DUSTY_BLUE  "\033[38;2;109;130;153m"
#define SOFT_PURPLE "\033[38;2;150;120;170m"
#define RESET       "\033[0m"

int main()
{
	std::cout << SOFT_PURPLE;
	std::cout << "============================================================\n";
	std::cout << "                  Bureaucrat & Forms Test\n";
	std::cout << "============================================================\n\n";
	std::cout << RESET;


	try {
		std::cout << DUSTY_BLUE;
		std::cout << "--------------- Creating Bureaucrats ---------------\n";
		std::cout << RESET;

		Bureaucrat Nana("Nana", 140);
		Bureaucrat Hayaser("Hayaser", 50);
		Bureaucrat Sose("Sose", 1);

		std::cout << SAGE_GREEN;
		std::cout << Nana << std::endl;
		std::cout << Hayaser << std::endl;
		std::cout << Sose << std::endl;
		std::cout << RESET;

		std::cout << DUSTY_BLUE;
		std::cout << "\n--------------- Creating Forms ---------------\n";
		std::cout << RESET;

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Marvin");
		PresidentialPardonForm pardon("Ford");

		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		std::cout << DUSTY_BLUE;
		std::cout << "\n--------------- Signing Forms ---------------\n";
		std::cout << RESET;

		Nana.signForm(shrub);
		Hayaser.signForm(robot);
		Sose.signForm(pardon);

		std::cout << DUSTY_BLUE;
		std::cout << "\n--------------- Executing Forms ---------------\n";
		std::cout << RESET;

		std::cout << SAGE_GREEN;
		std::cout << "\nShrubbery :\n";
		std::cout << RESET;

		Hayaser.executeForm(shrub);

		std::cout << SAGE_GREEN;
		std::cout << "\nRobotomy :\n";
		std::cout << RESET;

		Hayaser.executeForm(robot);

		std::cout << SAGE_GREEN;
		std::cout << "\nPresidential Pardon:\n";
		std::cout << RESET;

		Sose.executeForm(pardon);

		std::cout << DUSTY_BLUE;
		std::cout << "\n--------------- Unsigned Form Test ---------------\n";
		std::cout << RESET;

		ShrubberyCreationForm office("office");

		Hayaser.executeForm(office);

		std::cout << DUSTY_BLUE;
		std::cout << "\n--------------- Grade Error Test ---------------\n";
		std::cout << RESET;

		try {
			Bureaucrat wrong("Wrong", 200);
		}
		catch (std::exception &e) {
			std::cout << "Exception: "
			          << e.what()
			          << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: "
		          << e.what()
		          << std::endl;
	}

	return 0;
}