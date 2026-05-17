#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << GREEN << "[Cat]" << RESET
		<< " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << GREEN << "[Cat]" << RESET
		<< " copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << GREEN << "[Cat]" << RESET
		<< " assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << GREEN << "[Cat]" << RESET
		<< " destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << GREEN << "[Cat]" << RESET
		<< " Meow! Meow!" << std::endl;
}