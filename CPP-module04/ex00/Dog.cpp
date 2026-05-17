#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << GREEN << "[Dog]" << RESET << " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
        std::cout << GREEN << "[Dog]" << RESET << " copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << GREEN << "[Dog]" << RESET << " assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog(void)
{
    std::cout << GREEN << "[Dog]" << RESET << " destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << GREEN << "[Dog]" << RESET << " Woof! Woof!"  << std::endl;
}