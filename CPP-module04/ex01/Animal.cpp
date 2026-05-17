#include "Animal.hpp"

Animal::Animal(void) : _type("Undefined")
{
    std::cout << GREEN << "[Animal]" << RESET  <<  " default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << GREEN << "[Animal]" << RESET " constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << GREEN << "[Animal]" << RESET " copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << GREEN << "[Animal]" << RESET " assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal(void)
{
    std::cout << GREEN << "[Animal]" << RESET " destructor called" << std::endl;
}

const std::string& Animal::getType() const
{
	return _type;
}

void Animal::makeSound(void) const
{
	std::cout << GREEN << "[Animal]" << RESET " sound is undefined" << std::endl;
}