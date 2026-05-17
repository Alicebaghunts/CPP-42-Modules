#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "[WrongCat]" << RESET << " constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << GREEN << "[WrongCat]" << RESET << " copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
        WrongAnimal::operator=(other);
	std::cout << GREEN << "[WrongCat]" << RESET << " assignment operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << GREEN << "[WrongCat]" << RESET << " destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << GREEN << "[WrongCat]" << RESET << " Meow Meooooow???" << std::endl;
}