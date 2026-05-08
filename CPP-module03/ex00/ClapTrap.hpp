#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	int HitPoints;
	int EnergyPoints;
	int AttackDamage;

public:
	ClapTrap(std::string const& name);
	ClapTrap(ClapTrap const& other);
	ClapTrap& operator=(ClapTrap const& rhs);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
