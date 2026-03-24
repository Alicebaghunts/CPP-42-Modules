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

void	Harl::filter(std::string level)
{
	enum LevelKind { INV = -1, L_DEBUG, L_INFO, L_WARNING, L_ERROR };

	LevelKind	k = INV;
	if (level == "DEBUG")
		k = L_DEBUG;
	else if (level == "INFO")
		k = L_INFO;
	else if (level == "WARNING")
		k = L_WARNING;
	else if (level == "ERROR")
		k = L_ERROR;

	switch (k)
	{
		case L_DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			debug();
		case L_INFO:
			std::cout << "[ INFO ]" << std::endl;
			info();
		case L_WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			warning();
		case L_ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
