#include "Brain.hpp"

Brain::Brain()
{
    std::cout << GREEN << "[Brain] default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    for (unsigned int i = 0; i < size; i++)
        this->ideas[i] = other.ideas[i];
    std::cout << "[Brain] copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (unsigned int i = 0; i < size; i++)
            this->ideas[i] = other.ideas[i];
    }
    std::cout << "[Brain] assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "[Brain] destructor called" << std::endl;
}

void Brain::setIdea(unsigned int index, std::string idea)
{
    if (index < size)
        ideas[index] = idea;
}

std::string Brain::getIdea(unsigned int index) const
{
    if (index < size)
        return ideas[index];
    return "No idea...";
}