#include "Harl.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <LEVEL>" << std::endl;
		return 1;
	}

	Harl	harl;

	harl.filter(argv[1]);
	return 0;
}
