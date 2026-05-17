#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->brain = new Brain();
	this->_type = "Cat";
	std::cout << GREEN << "[Cat]" << RESET
		<< " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	this->_type = other._type;
	std::cout << GREEN << "[Cat]" << RESET
		<< " copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << GREEN << "[Cat]" << RESET
		<< " assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << GREEN << "[Cat]" << RESET
		<< " destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << GREEN << "[Cat]" << RESET
		<< " Meow! Meow!" << std::endl;
}