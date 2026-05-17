#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog"), _brain(new Brain())
{
	std::cout << GREEN << "[Dog]" << RESET
		<< " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << GREEN << "[Dog]" << RESET
		<< " copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other); 
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << GREEN << "[Dog]" << RESET
		<< " assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << GREEN << "[Dog]" << RESET
		<< " destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << GREEN << "[Dog]" << RESET
		<< " Woof! Woof!" << std::endl;
}