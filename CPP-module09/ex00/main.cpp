#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc;
		btc.LoadDataBase("data.csv");
		btc.ProcessFile(argv[1]);
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
