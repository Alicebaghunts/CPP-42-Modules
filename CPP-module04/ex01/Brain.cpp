#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = "";
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(Brain const& other)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy-constructed" << std::endl;
}

Brain& Brain::operator=(Brain const& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = rhs.ideas[i];
	}
	std::cout << "Brain assigned" << std::endl;
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructed" << std::endl;
}
