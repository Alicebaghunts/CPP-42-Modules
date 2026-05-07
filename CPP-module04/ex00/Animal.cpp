#include "Animal.hpp"

Animal::Animal(void) : type("Animal") { std::cout << "Animal constructed" << std::endl; }
Animal::Animal(Animal const& other) : type(other.type) { std::cout << "Animal copy-constructed" << std::endl; }
Animal& Animal::operator=(Animal const& rhs) { if (this != &rhs) type = rhs.type; std::cout << "Animal assigned" << std::endl; return *this; }
Animal::~Animal(void) { std::cout << "Animal destructed" << std::endl; }

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }
std::string const& Animal::getType() const { return type; }
