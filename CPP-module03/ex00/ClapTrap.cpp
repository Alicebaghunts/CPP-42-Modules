#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const& name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other)
{
	name = other.name;
	HitPoints = other.HitPoints;
	EnergyPoints = other.EnergyPoints;
	AttackDamage = other.AttackDamage;
	std::cout << "ClapTrap " << name << " copy-constructed" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	std::cout << "ClapTrap " << name << " assigned" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (HitPoints <= 0 || EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't attack" << std::endl;
		return;
	}
	EnergyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	HitPoints -= amount;
	if (HitPoints < 0) HitPoints = 0;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoints <= 0 || EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't be repaired" << std::endl;
		return;
	}
	EnergyPoints--;
	HitPoints += amount;
	std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl;
}
