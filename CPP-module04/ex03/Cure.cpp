#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << DUSTY_BLUE << "[Cure]" << RESET << " Default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << DUSTY_BLUE << "[Cure]" << RESET << " Copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
        AMateria::operator=(other);
    std::cout << DUSTY_BLUE << "[Cure]" << RESET << " Assignment operator called" << std::endl;
    return *this;
}

Cure::~Cure()
{
    std::cout << DUSTY_BLUE << "[Cure]" << RESET << " Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    std::cout << DUSTY_BLUE << "[Cure]" << RESET << " clone() called" << std::endl;
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}