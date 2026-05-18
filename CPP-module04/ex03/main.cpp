#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "............ MATERIA SOURCE TEST ............\n" << std::endl;

	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n............ CREATE MATERIA TEST ............\n" << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("cure");

	std::cout << "\n............ CHARACTER TEST ............\n" << std::endl;

	ICharacter* me = new Character("me");

	me->equip(tmp);
	me->equip(tmp2);

	ICharacter* yanus = new Character("yanus");

	me->use(0, *yanus);
	me->use(1, *yanus);

	std::cout << "\n............ UNEQUIP TEST ............\n" << std::endl;

	me->unequip(0);
	me->unequip(1);

	std::cout << "\n............ CLEANUP ............\n" << std::endl;

	delete yanus;
	delete me;
	delete src;

    delete tmp;
    delete tmp2;
	return 0;
}