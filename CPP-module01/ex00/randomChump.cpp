#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie ch = Zombie(name);

	ch.announce();
	return ;
}