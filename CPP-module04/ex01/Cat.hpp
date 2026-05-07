#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;

public:
	Cat(void);
	Cat(Cat const& other);
	Cat& operator=(Cat const& rhs);
	~Cat(void);

	virtual void makeSound() const;
	Brain* getBrain() const;
};

#endif
