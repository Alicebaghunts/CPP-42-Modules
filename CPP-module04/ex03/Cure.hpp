#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure const& other);
	Cure& operator=(Cure const& rhs);
	~Cure(void);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
