#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << GREEN << "===== DIAMONDTRAP TEST =====" << RESET << std::endl;

    DiamondTrap defaultTrap;
    std::cout << std::endl;

    DiamondTrap d("Alisa");
    std::cout << std::endl;

    std::cout << GREEN << "----- ACTIONS -----" << RESET << std::endl;
    d.attack("EnemyBot");
    d.takeDamage(25);
    d.beRepaired(15);
    std::cout << std::endl;

    std::cout << GREEN << "----- SPECIAL ABILITIES -----" << RESET << std::endl;
    d.guardGate();
    d.highFivesGuys();
    d.whoAmI();
    std::cout << std::endl;

    std::cout << GREEN << "----- COPY TEST -----" << RESET << std::endl;
    DiamondTrap copyTrap(d);
    copyTrap.whoAmI();
    std::cout << std::endl;

    std::cout << GREEN << "----- ASSIGNMENT TEST -----" << RESET << std::endl;
    DiamondTrap assignTrap("Temp");
    assignTrap = d;
    assignTrap.whoAmI();
    std::cout << std::endl;

    std::cout << GREEN << "===== END OF MAIN =====" << RESET << std::endl;

    return 0;
}