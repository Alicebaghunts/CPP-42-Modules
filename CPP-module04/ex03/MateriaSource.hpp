#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* storage[4];

public:
	MateriaSource(void);
	MateriaSource(MateriaSource const& other);
	MateriaSource& operator=(MateriaSource const& rhs);
	~MateriaSource();

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif
