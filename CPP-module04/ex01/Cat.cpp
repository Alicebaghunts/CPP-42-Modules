#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(Cat const& other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat copy-constructed" << std::endl;
}

Cat& Cat::operator=(Cat const& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (brain)
			delete brain;
		brain = new Brain(*rhs.brain);
	}
	std::cout << "Cat assigned" << std::endl;
	return *this;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }

Brain* Cat::getBrain() const { return brain; }
