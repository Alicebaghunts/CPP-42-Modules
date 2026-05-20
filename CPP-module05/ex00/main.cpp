#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << DUSTY_BLUE << "\n------ Bureaucrat Test ------\n\n" << RESET;

	try {
		Bureaucrat president("Nikol", 1);
		Bureaucrat minister("Minister", 50);
		Bureaucrat intern("Intern", 150);

		std::cout << president << std::endl;
		std::cout << minister << std::endl;
		std::cout << intern << std::endl;

		std::cout << SAGE_GREEN << "\n------ Testing increment and decrement ------\n" << RESET << std::endl;
		minister.incrementGrade();
		std::cout << "After increment Minister: " << minister << std::endl;
		intern.decrementGrade();
		std::cout << "After decrement Intern: " << intern << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << SOFT_PURPLE << "\n------ Testing exceptions ------\n" << RESET;

	try {
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (std::exception &e) {
		std::cout << "Test 1: " << e.what() << std::endl;
	}

	try {
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (std::exception &e) {
		std::cout << "Test 2: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Test", 1);
		b.incrementGrade(); 
	}
	catch (std::exception &e) {
		std::cout << "Test 3: " << e.what() << std::endl << std::endl;
	}

	return (0);
}