#include "WrongCat.hpp"

WrongCat::WrongCat(void) { type = "WrongCat"; std::cout << "WrongCat constructed" << std::endl; }
WrongCat::WrongCat(WrongCat const& other) : WrongAnimal(other) { std::cout << "WrongCat copy-constructed" << std::endl; }
WrongCat& WrongCat::operator=(WrongCat const& rhs) { if (this != &rhs) WrongAnimal::operator=(rhs); std::cout << "WrongCat assigned" << std::endl; return *this; }
WrongCat::~WrongCat(void) { std::cout << "WrongCat destructed" << std::endl; }

void WrongCat::makeSound() const { std::cout << "Wrong meow" << std::endl; }
