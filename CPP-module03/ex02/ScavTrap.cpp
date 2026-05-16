#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("default")
{
    _hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name ) : ClapTrap(name)
{
    _hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
 {
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
 }

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
    if (!canMove())
		return ;
	--_energyPoints;
	std::cout << "ScavTrap " << _name << " attacks " << target
        << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}