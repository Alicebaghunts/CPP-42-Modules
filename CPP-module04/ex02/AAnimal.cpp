#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Undefined")
{
	std::cout << GREEN << "[AAnimal]" << RESET
		<< " default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << GREEN << "[AAnimal]" << RESET
		<< " constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << GREEN << "[AAnimal]" << RESET
		<< " copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		_type = other._type;

	std::cout << GREEN << "[AAnimal]" << RESET
		<< " assignment operator called" << std::endl;

	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << GREEN << "[AAnimal]" << RESET
		<< " destructor called" << std::endl;
}

const std::string& AAnimal::getType() const
{
	return _type;
}