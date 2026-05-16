#include "ScavTrap.hpp"

int main(void)
{
	std::cout << GREEN << "===== CONSTRUCTOR TEST =====" << RESET << std::endl;

	ScavTrap a("Larice");
	ScavTrap b("Alice");

	std::cout << GREEN << "===== COPY TEST =====" << RESET << std::endl;
	ScavTrap c = a;
	b = a;
	std::cout << GREEN << "===== ACTION TEST =====" << RESET << std::endl;

	a.attack("Enemy");
	a.takeDamage(30);
	a.beRepaired(20);

	std::cout << GREEN << "===== SPECIAL ABILITY =====" << RESET << std::endl;
	a.guardGate();
	std::cout << GREEN << "===== END OF SCOPE =====" << RESET << std::endl;
	return 0;
}