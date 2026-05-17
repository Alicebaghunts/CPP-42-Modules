#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	std::cout << "\n.........POLYMORPHISM TEST.........\n" << std::endl;

	const Animal* a = new Dog();
	const Animal* b = new Cat();

	std::cout << a->getType() << std::endl;
	std::cout << b->getType() << std::endl;

	a->makeSound();
	b->makeSound();

	std::cout << "\n.............ARRAY TEST............\n" << std::endl;

	const Animal* animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n..............COPY TEST.............\n" << std::endl;

	Dog x;
	Dog y = x;
	Dog z;

	z = x;

	std::cout << "\n.................DONE...............\n" << std::endl;

	delete a;
	delete b;

	return 0;
}