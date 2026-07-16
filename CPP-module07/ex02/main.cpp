#include <iostream>
#include <string>
#include "Array.hpp"

# define RESET   "\033[0m"
# define PURPLE  "\033[38;2;150;120;170m"

struct Person
{
	int age;
	std::string name;
};

int main()
{
	std::cout << PURPLE << "============ Empty Array ============" << RESET << std::endl;

	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;

	try {
		std::cout << empty[0] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n" << PURPLE << "========== Integer Array ============" << RESET << std::endl;

	Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i + 1;

	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";

	std::cout << std::endl;

	std::cout << "\n" << PURPLE << "========= Copy Constructor =========" << RESET << std::endl;

	Array<int> copy(numbers);

	copy[0] = 100;

	std::cout << "Original: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";

	std::cout << "\nCopy: ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";

	std::cout << std::endl;

	std::cout << "\n" << PURPLE << "======== Assignment Operator =======" << RESET << std::endl;

	Array<int> assign;
	assign = numbers;

	assign[1] = 200;

	std::cout << "Original: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";

	std::cout << "\nAssigned: ";
	for (unsigned int i = 0; i < assign.size(); i++)
		std::cout << assign[i] << " ";

	std::cout << std::endl;

	std::cout << "\n" << PURPLE << "============ Const Array ============" << RESET << std::endl;

	const Array<int> constArray(numbers);

	for (unsigned int i = 0; i < constArray.size(); i++)
		std::cout << constArray[i] << " ";

	std::cout << std::endl;

	std::cout << "\n" << PURPLE << "=========== String Array ============" << RESET << std::endl;

	Array<std::string> words(3);

	words[0] = "Hello";
	words[1] = "42";
	words[2] = "School";

	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << " ";

	std::cout << std::endl;

	std::cout << "\n" << PURPLE << "=========== Struct Array ============" << RESET << std::endl;

	Array<Person> people(2);

	people[0].name = "Alice";
	people[0].age = 20;

	people[1].name = "Bob";
	people[1].age = 30;

	for (unsigned int i = 0; i < people.size(); i++)
		std::cout << people[i].name << " " << people[i].age << std::endl;

	std::cout << "\n" << PURPLE << "=========== Out of Bounds ===========" << RESET << std::endl;

	try {
		std::cout << numbers[100] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		numbers[50] = 5;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}