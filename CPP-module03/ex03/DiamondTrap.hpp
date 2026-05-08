#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;

public:
	DiamondTrap(std::string const& name);
	DiamondTrap(DiamondTrap const& other);
	DiamondTrap& operator=(DiamondTrap const& rhs);
	~DiamondTrap();

	using ScavTrap::attack;
	void whoAmI();
};

#endif
