#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Alice");
	a.attack("Target");
	a.takeDamage(5);
	a.beRepaired(3);
	return 0;
}
