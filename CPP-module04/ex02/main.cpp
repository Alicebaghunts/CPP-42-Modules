#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// Animal cannot be instantiated because it's abstract now
	// const Animal* meta = new Animal(); // should fail
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	delete j;
	delete i;
	return 0;
}
