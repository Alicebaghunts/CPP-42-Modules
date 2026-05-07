#include "Dog.hpp"

Dog::Dog(void) { type = "Dog"; std::cout << "Dog constructed" << std::endl; }
Dog::Dog(Dog const& other) : Animal(other) { std::cout << "Dog copy-constructed" << std::endl; }
Dog& Dog::operator=(Dog const& rhs) { if (this != &rhs) Animal::operator=(rhs); std::cout << "Dog assigned" << std::endl; return *this; }
Dog::~Dog(void) { std::cout << "Dog destructed" << std::endl; }

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
