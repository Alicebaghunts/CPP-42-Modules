#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << GREEN << "===== CLAPTRAP TEST =====" << RESET << std::endl;

	ClapTrap a("Alice");
	a.attack("Enemy");
	a.takeDamage(5);
	a.beRepaired(3);

	std::cout << GREEN << "===== FRAGTRAP TEST =====" << RESET << std::endl;

	FragTrap b("Larice");
	b.attack("Monster");
	b.takeDamage(30);
	b.beRepaired(20);
	b.highFivesGuys();

	std::cout << GREEN << "===== COPY TEST =====" << RESET << std::endl;

	FragTrap c(b);
	c.highFivesGuys();

	std::cout << GREEN << "===== ASSIGNMENT TEST =====" << RESET << std::endl;

	FragTrap d;
	d = b;
	d.highFivesGuys();

	std::cout << GREEN << "===== END OF MAIN =====" << RESET << std::endl;

	return 0;
}