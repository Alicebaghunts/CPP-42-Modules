#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
		AMateria* _floor[100];
		int _floorCount;

	public:
		Character();
		Character(const std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character();

		std::string const& getName() const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif