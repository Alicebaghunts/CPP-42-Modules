#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const int N = 4;
	Animal* animals[N];

	for (int i = 0; i < N; ++i)
	{
		if (i < N/2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < N; ++i)
	{
		animals[i]->makeSound();
	}

	for (int i = 0; i < N; ++i)
	{
		delete animals[i];
	}

	// deep copy test
	Dog original;
	original.getBrain()->ideas[0] = "Chase the mailman";
	Dog copy = original; // copy-constructed
	copy.getBrain()->ideas[0] = "Eat the homework";

	std::cout << "original idea: " << original.getBrain()->ideas[0] << std::endl;
	std::cout << "copy idea: " << copy.getBrain()->ideas[0] << std::endl;

	return 0;
}
