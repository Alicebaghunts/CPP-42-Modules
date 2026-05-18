#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_storage[i])
				delete _storage[i];
			_storage[i] = NULL;

			if (other._storage[i])
				_storage[i] = other._storage[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_storage[i])
			delete _storage[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (_storage[i] == NULL)
		{
			_storage[i] = m->clone();
			delete m;
			return;
		}
	}
	// storage full: delete passed materia to avoid leak
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_storage[i] && _storage[i]->getType() == type)
			return _storage[i]->clone();
	}
	return NULL;
}