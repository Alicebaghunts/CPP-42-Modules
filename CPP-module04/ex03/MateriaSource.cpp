#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
		storage[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& other)
{
	for (int i = 0; i < 4; ++i)
		storage[i] = other.storage[i] ? other.storage[i]->clone() : NULL;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (storage[i]) delete storage[i];
			storage[i] = rhs.storage[i] ? rhs.storage[i]->clone() : NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		if (storage[i]) delete storage[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m) return;
	for (int i = 0; i < 4; ++i)
	{
		if (!storage[i])
		{
			storage[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (storage[i] && storage[i]->getType() == type)
			return storage[i]->clone();
	}
	return NULL;
}
