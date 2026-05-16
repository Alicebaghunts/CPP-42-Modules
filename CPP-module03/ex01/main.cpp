#include "ScavTrap.hpp"

int main(void)
{
	std::cout << GREEN << "\n--- CONSTRUCTOR TEST ---\n" << RESET << std::endl;

	ScavTrap a("Larice");
	ScavTrap b("Alice");

	std::cout << GREEN << "\n--- COPY TEST ---\n" << RESET << std::endl;

	ScavTrap c = a;
	b = a;

	std::cout << GREEN << "\n--- ACTION TEST ---\n" << RESET << std::endl;

	a.attack("Enemy");
	a.takeDamage(30);
	a.beRepaired(20);

	std::cout << GREEN << "\n--- SPECIAL ABILITY ---\n" << RESET << std::endl;

	a.guardGate();

	std::cout << GREEN << "\n--- END OF SCOPE ---\n" << RESET << std::endl;

	return 0;
}