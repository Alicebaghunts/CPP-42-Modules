#include "Zombie.hpp"

int	main(void)
{
	Zombie *z1 = zombieHorde(5, "Alice");

	if (z1)
	{
		for (int i = 0; i < 5; ++i)
		{
			z1[i].announce();
		}
		delete[] z1;
	}

	Zombie *z2 = zombieHorde(1, "Larice");

	if (z2)
	{
		z2[0].announce();
		delete[] z2;
	}

	Zombie *empty = zombieHorde(0, "Nobody");
	if (empty == NULL)
	{
		std::cout << "No zombies created (N=0)" << std::endl;
	}
	return (0);
}