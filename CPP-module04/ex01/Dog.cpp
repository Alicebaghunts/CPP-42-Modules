#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(Dog const& other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog copy-constructed" << std::endl;
}

Dog& Dog::operator=(Dog const& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (brain)
			delete brain;
		brain = new Brain(*rhs.brain);
	}
	std::cout << "Dog assigned" << std::endl;
	return *this;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }

Brain* Dog::getBrain() const { return brain; }
