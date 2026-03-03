#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon(void)
{
}

const std::string& Weapon::getType(void) const
{
	return this->type;
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}