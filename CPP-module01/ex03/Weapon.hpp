#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string&	getType(void) const;
	void    setType(std::string newType);
};

#endif