#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
public:
	std::string ideas[100];

	Brain(void);
	Brain(Brain const& other);
	Brain& operator=(Brain const& rhs);
	~Brain(void);
};

#endif
