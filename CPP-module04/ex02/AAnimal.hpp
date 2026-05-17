#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

# define GREEN "\033[32m"
# define RESET "\033[0m"

class AAnimal
{
  protected:
	std::string _type;

  public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	virtual void makeSound() const = 0;
	const std::string &getType() const;
};

#endif