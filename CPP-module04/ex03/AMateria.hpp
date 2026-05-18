#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#define SAGE_GREEN  "\033[38;2;163;177;138m"
#define DUSTY_BLUE  "\033[38;2;109;130;153m"
#define SOFT_PURPLE "\033[38;2;150;120;170m"
#define RESET       "\033[0m"

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		explicit AMateria(std::string const& type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();

		std::string const& getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif