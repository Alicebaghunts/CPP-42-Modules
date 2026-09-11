#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pm;
		pm.parseArgs(argc, argv);
		pm.run();
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
