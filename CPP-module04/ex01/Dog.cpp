#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->brain = new Brain();
	this->_type = "Dog";
    std::cout << GREEN << "[Dog]" << RESET << " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	this->_type = other._type;
	std::cout << GREEN << "[Dog]" << RESET
		<< " copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << GREEN << "[Dog]" << RESET
		<< " assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
    std::cout << GREEN << "[Dog]" << RESET << " destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << GREEN << "[Dog]" << RESET << " Woof! Woof!"  << std::endl;
}