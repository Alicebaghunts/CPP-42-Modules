#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

# define GREEN "\033[32m"
# define RESET "\033[0m"

class Brain
{
private:
    static const unsigned int size = 100;
    std::string ideas[size];

public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    void setIdea(unsigned int index, std::string idea);
    std::string getIdea(unsigned int index) const;
};

#endif