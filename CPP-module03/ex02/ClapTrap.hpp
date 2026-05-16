#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define GREEN "\033[32m"
# define RESET "\033[0m"

class ClapTrap
{
protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string const& name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:
	bool	isAlive(void) const;
	bool	canMove(void) const;
};

#endif