#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") { std::cout << "WrongAnimal constructed" << std::endl; }
WrongAnimal::WrongAnimal(WrongAnimal const& other) : type(other.type) { std::cout << "WrongAnimal copy-constructed" << std::endl; }
WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs) { if (this != &rhs) type = rhs.type; std::cout << "WrongAnimal assigned" << std::endl; return *this; }
WrongAnimal::~WrongAnimal(void) { std::cout << "WrongAnimal destructed" << std::endl; }

void WrongAnimal::makeSound() const { std::cout << "Wrong animal sound" << std::endl; }
std::string const& WrongAnimal::getType() const { return type; }
