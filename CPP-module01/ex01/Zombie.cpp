#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie(void)
{
}

void Zombie::announce(void) const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        horde[i] = Zombie(name);
    }
    return horde;
}