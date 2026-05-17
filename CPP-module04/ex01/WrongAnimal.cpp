#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << GREEN << "[WrongAnimal]" << RESET " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &a_type) : type(a_type)
{
	std::cout << GREEN << "[WrongAnimal]" << RESET " constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
	std::cout << GREEN << "[WrongAnimal]" << RESET " copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;

	std::cout << GREEN << "[WrongAnimal]" << RESET " assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "[WrongAnimal]" << RESET " destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << GREEN << "[WrongAnimal]" << RESET " sound is undefined" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}