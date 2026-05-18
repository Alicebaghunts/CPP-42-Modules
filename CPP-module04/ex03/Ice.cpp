#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << SOFT_PURPLE << "[Ice]" << RESET << " Default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout << SOFT_PURPLE << "[Ice]" << RESET << " Copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        AMateria::operator=(other);
    std::cout << SOFT_PURPLE << "[Ice]" << RESET << " Assignment operator called" << std::endl;
    return *this;
}

Ice::~Ice()
{
    std::cout << SOFT_PURPLE << "[Ice]" << RESET << " Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    std::cout << SOFT_PURPLE << "[Ice]" << RESET << " clone() called" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}