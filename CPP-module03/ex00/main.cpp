#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Yanus");
    ClapTrap b("Tiki");

    std::cout << GREEN << "\n-- Direct attack simulation --\n" << RESET << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        a.attack("Tiki");
        b.takeDamage(3);
    }
    std::cout << GREEN << "\n-- Energy exhaustion test --\n" << RESET << std::endl;
    for (int i = 0; i < 6; ++i)
        a.attack("Xasb");
    std::cout << GREEN << "\n-- Dead robot behavior --\n" << RESET << std::endl;

    b.takeDamage(100);
    b.attack("Nothing");
    b.beRepaired(5);

    std::cout << GREEN << "\n-- End --\n" << RESET << std::endl;
    return 0;
}