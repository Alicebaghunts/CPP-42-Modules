#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const& nm) : ClapTrap(nm + "_clap_name"), FragTrap(nm), ScavTrap(nm), name(nm)
{
	HitPoints = FragTrap::HitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	std::cout << "DiamondTrap " << name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << "DiamondTrap " << name << " copy-constructed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		name = rhs.name;
	}
	std::cout << "DiamondTrap " << name << " assigned" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destructed" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}
