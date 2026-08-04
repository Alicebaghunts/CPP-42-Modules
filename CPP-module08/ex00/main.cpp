#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);

	try {
		std::vector<int>::const_iterator it = easyfind(numbers, 30);
		std::cout << "Found " << *it << " in vector" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int> values;
	values.push_back(5);
	values.push_back(15);
	values.push_back(25);

	try {
		std::list<int>::const_iterator it = easyfind(values, 100);
		std::cout << "Found " << *it << " in list" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
