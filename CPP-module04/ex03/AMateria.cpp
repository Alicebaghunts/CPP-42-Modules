#include "AMateria.hpp"

AMateria::AMateria(std::string const & t) : type(t) {}
AMateria::AMateria(AMateria const& other) : type(other.type) {}
AMateria& AMateria::operator=(AMateria const& rhs) { if (this != &rhs) type = rhs.type; return *this; }
AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target) { (void)target; }
