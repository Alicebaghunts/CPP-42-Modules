#include "Animal.hpp"

Animal::Animal(void) : type("Undefined")
{
    std::cout << GREEN << "[Animal]" << RESET  <<  " default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << GREEN << "[Animal]" << RESET " constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << GREEN << "[Animal]" << RESET " copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        type = other.type;
    std::cout << GREEN << "[Animal]" << RESET " assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal(void)
{
    std::cout << GREEN << "[Animal]" << RESET " destructor called" << std::endl;
}

const std::string& Animal::getType() const
{
	return type;
}

void Animal::makeSound(void) const
{
	std::cout << GREEN << "[Animal]" << RESET " sound is undefined" << std::endl;
}