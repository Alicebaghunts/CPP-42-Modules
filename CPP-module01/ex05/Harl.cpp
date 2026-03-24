#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void (Harl::*ComplaintFn)(void);

	struct LevelEntry
	{
		const char*	name;
		ComplaintFn	fn;
	};

	static const LevelEntry	table[] = {
		{ "DEBUG", &Harl::debug },
		{ "INFO", &Harl::info },
		{ "WARNING", &Harl::warning },
		{ "ERROR", &Harl::error }
	};

	const size_t	n = sizeof(table) / sizeof(table[0]);

	for (size_t i = 0; i < n; ++i)
	{
		if (level == table[i].name)
		{
			(this->*table[i].fn)();
			return;
		}
	}
}
