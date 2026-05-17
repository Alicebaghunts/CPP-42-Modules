#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

# define GREEN "\033[32m"
# define RESET "\033[0m"

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
        WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();

		void makeSound() const;
		std::string getType() const;
};

#endif