#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED << "Error" << RESET << std::endl;
		return 1;
	}

	try {
		RPN rpn;
		std::cout << rpn.calculateExpression(argv[1]) << std::endl;
	}
	catch (const std::exception &e){
		std::cout << RED << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
