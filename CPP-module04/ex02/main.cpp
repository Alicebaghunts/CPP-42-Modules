#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	std::cout << "\n......... POLYMORPHISM TEST .........\n" << std::endl;

	const AAnimal* a = new Dog();
	const AAnimal* b = new Cat();

	std::cout << a->getType() << std::endl;
	std::cout << b->getType() << std::endl;

	a->makeSound();
	b->makeSound();

	std::cout << "\n......... CLEAN DELETE TEST .........\n" << std::endl;

	delete a;
	delete b;

	return 0;
}