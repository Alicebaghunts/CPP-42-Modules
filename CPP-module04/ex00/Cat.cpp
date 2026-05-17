#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << GREEN << "[Cat]" << RESET << " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
        std::cout << GREEN << "[Cat]" << RESET << " copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << GREEN << "[Cat]" << RESET << " assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat(void)
{
    std::cout << GREEN << "[Cat]" << RESET << " destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << GREEN << "[Cat]" << RESET << " Meow! Meow!"  << std::endl;
}