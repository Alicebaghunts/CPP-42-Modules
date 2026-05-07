#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const& other);
	Dog& operator=(Dog const& rhs);
	~Dog(void);

	virtual void makeSound() const;
};

#endif
