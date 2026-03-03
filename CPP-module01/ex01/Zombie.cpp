#include "Zombie.hpp"

Zombie::Zombie() : _name("Default")
{
	//std::cout << "Zombie created!" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	//std::cout << "Zombie " << this->_name << " created!" << std::endl;
}

Zombie::~Zombie()
{
	//std::cout << "Zombie " << this->_name << " destroyed!" << std::endl;
}

void Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}