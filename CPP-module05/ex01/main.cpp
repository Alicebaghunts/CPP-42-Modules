#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << DUSTY_BLUE << "\n------ Form Test ------\n\n" << RESET;

	try {
		Bureaucrat boss("Bruno", 10);
		Bureaucrat employee("Employee", 60);
		Bureaucrat intern("Intern", 150);

		Form contract("Contract", 50, 30);
		Form secret("Secret Document", 20, 10);

		std::cout << contract << std::endl;
		std::cout << secret << std::endl;

		std::cout << SAGE_GREEN << "\n------ Signing Tests ------\n" << RESET;
		
		boss.signForm(contract);
		employee.signForm(contract);
		intern.signForm(secret);
		std::cout << std::endl;

		std::cout << DUSTY_BLUE << "\n------ Final Form Status ------\n" << RESET;

		std::cout << contract << std::endl;
		std::cout << secret << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << SOFT_PURPLE << "\n------ Exception Tests ------\n" << RESET;

	try {
		Form badHigh("Vat High Form", 0, 20);
	}
	catch (std::exception &e) {
		std::cout << "Test 1: " << e.what() << std::endl;
	}

	try {
		Form badLow("Vat Low Form", 151, 20);
	}
	catch (std::exception &e) {
		std::cout << "Test 2: " << e.what() << std::endl;
	}

	try {
		Form badExecute("Vat Execute Form", 20, 0);
	}
	catch (std::exception &e) {
		std::cout << "Test 3: " << e.what() << std::endl;
	}

	return (0);
}