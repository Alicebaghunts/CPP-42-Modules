#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(Animal const& other);
	Animal& operator=(Animal const& rhs);
	virtual ~Animal(void);

	virtual void makeSound() const = 0; // pure virtual
	std::string const& getType() const;
};

#endif
