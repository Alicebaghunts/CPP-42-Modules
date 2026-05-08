#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const& other);
	WrongAnimal& operator=(WrongAnimal const& rhs);
	~WrongAnimal(void);

	void makeSound() const;
	std::string const& getType() const;
};

#endif
