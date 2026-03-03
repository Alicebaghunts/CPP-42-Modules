#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) { }

HumanB::~HumanB(void) { }

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (this->weapon == NULL)
	{
		std::cout << this->name << " has no weapon to attack with" << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
}