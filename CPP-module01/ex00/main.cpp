#include "Zombie.hpp"

int main(void)
{
    Zombie *z1 = newZombie("Max Verstappen");
    z1->announce();

    randomChump("Lando Noris");

    Zombie *z2 = newZombie("Charles Leclerc");
    z2->announce();

    randomChump("Carlos Sinze");

    Zombie *z3 = newZombie("Max");
    z3->announce();

    delete z1;
    delete z2;
    delete z3;

    return 0;
}