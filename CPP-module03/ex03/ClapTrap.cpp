#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
	_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

bool ClapTrap::isAlive() const
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << " is already dead" << std::endl;
		return false;
	}
	return true;
}

bool ClapTrap::canMove() const
{
	if (!isAlive())
		return false;
	if (_energyPoints <= 0)
	{
		std::cout << _name << " is out of energy points..." << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::attack(const std::string &target)
{
	if (!canMove())
		return ;
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target
        << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!isAlive())
		return ;
	if (static_cast<int>(amount) >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= static_cast<int>(amount);
	std::cout << _name << " takes " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!canMove())
		return ;
	_energyPoints--;
	_hitPoints += static_cast<int>(amount);
	std::cout << _name << " repaired itself for " << amount << " hit points" << std::endl;
}
