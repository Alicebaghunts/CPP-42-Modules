#include "Character.hpp"

Character::Character(std::string const& n) : name(n)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Character::Character(Character const& other) : name(other.name)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
}

Character& Character::operator=(Character const& rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		for (int i = 0; i < 4; ++i)
		{
			if (inventory[i])
				delete inventory[i];
			inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		if (inventory[i])
			delete inventory[i];
}

std::string const & Character::getName() const { return name; }

void Character::equip(AMateria* m)
{
	if (!m) return;
	for (int i = 0; i < 4; ++i)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >=4) return;
	inventory[idx] = NULL; // do not delete
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >=4) return;
	if (inventory[idx])
		inventory[idx]->use(target);
}
