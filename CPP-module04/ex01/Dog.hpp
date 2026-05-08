#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog(void);
	Dog(Dog const& other);
	Dog& operator=(Dog const& rhs);
	~Dog(void);

	virtual void makeSound() const;
	Brain* getBrain() const;
};

#endif
