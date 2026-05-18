#include "Character.hpp"

Character::Character() : _name("default"), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
}

Character::Character(const std::string name) : _name(name), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
}

Character::Character(const Character& other) : _name("default"), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
	*this = other;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;

        for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}

        for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	
        for (int i = 0; i < 100; i++)
		{
			if (_floor[i])
			{
				delete _floor[i];
				_floor[i] = NULL;
			}
			if (other._floor[i])
				_floor[i] = other._floor[i]->clone();
			else
				_floor[i] = NULL;
		}
		_floorCount = other._floorCount;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < 100; i++)
	{
		if (_floor[i])
			delete _floor[i];
	}
}

std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		if (_floorCount < 100)
		{
			_floor[_floorCount++] = _inventory[idx];
			_inventory[idx] = NULL;
		}
		else
		{
			delete _inventory[idx];
			_inventory[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}