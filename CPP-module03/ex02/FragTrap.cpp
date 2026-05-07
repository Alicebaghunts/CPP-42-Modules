#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const& name) : ClapTrap(name)
{
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << name << " constructed" << std::endl;
}

FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << name << " copy-constructed" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "FragTrap " << name << " assigned" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests high fives!" << std::endl;
}
