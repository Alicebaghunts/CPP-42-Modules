#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Yanus");
    ClapTrap b("Tiki");

    std::cout << "\n-- Direct attack simulation --\n" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        a.attack("Tiki");
        b.takeDamage(3);
    }
    std::cout << "\n-- Energy exhaustion test --\n" << std::endl;
    for (int i = 0; i < 6; ++i)
        a.attack("Xasb");
    std::cout << "\n-- Dead robot behavior --\n" << std::endl;

    b.takeDamage(100);
    b.attack("Nothing");
    b.beRepaired(5);

    std::cout << "\n-- End --\n" << std::endl;
    return 0;
}