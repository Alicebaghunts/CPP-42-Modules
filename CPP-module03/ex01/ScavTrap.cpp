#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name)
{
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << name << " copy-constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "ScavTrap " << name << " assigned" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (HitPoints <= 0 || EnergyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " can't attack" << std::endl;
		return;
	}
	EnergyPoints--;
	std::cout << "ScavTrap " << name << " scav attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
