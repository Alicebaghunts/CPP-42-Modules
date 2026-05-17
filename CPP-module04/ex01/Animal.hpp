#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

# define GREEN "\033[32m"
# define RESET "\033[0m"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string _type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		virtual void makeSound() const;
		const std::string& getType() const;
};

#endif