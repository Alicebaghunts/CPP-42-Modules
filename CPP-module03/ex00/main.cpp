#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Yanus");
    ClapTrap b("Tiki");

    std::cout << GREEN << "===== Direct attack simulation =====" << RESET << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        a.attack("Tiki");
        b.takeDamage(3);
    }
    std::cout << GREEN << "===== Energy exhaustion test =====" << RESET << std::endl;
    for (int i = 0; i < 6; ++i)
        a.attack("Xasb");
    std::cout << GREEN << "===== Dead robot behavior =====" << RESET << std::endl;

    b.takeDamage(100);
    b.attack("Nothing");
    b.beRepaired(5);

    std::cout << GREEN << "===== End =====" << RESET << std::endl;
    return 0;
}