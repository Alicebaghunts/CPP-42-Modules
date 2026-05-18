#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default")
{
    std::cout << SAGE_GREEN << "[AMateria]" << RESET << " Default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
    std::cout << SAGE_GREEN << "[AMateria]" << RESET << " Parameter constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
    std::cout << SAGE_GREEN << "[AMateria]" << RESET << " Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << SAGE_GREEN << "[AMateria]" << RESET << " Assignment operator called" << std::endl;
    return *this;
} 

AMateria::~AMateria(void)
{
    std::cout << SAGE_GREEN << "[AMateria]" << RESET << " destructor called" << std::endl;
    
}

std::string const& AMateria::getType(void) const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	static_cast<void>(target);
}