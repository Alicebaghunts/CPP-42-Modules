#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->brain = new Brain();
	this->_type = "Dog";
    std::cout << GREEN << "[Dog]" << RESET << " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
        std::cout << GREEN << "[Dog]" << RESET << " copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}
Dog::~Dog(void)
{
    delete brain;
    std::cout << GREEN << "[Dog]" << RESET << " destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << GREEN << "[Dog]" << RESET << " Woof! Woof!"  << std::endl;
}