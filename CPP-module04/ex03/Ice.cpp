#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {}
Ice::Ice(Ice const& other) : AMateria(other) {}
Ice& Ice::operator=(Ice const& rhs) { AMateria::operator=(rhs); return *this; }
Ice::~Ice(void) {}

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
