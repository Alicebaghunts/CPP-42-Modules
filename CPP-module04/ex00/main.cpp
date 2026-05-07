#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	wa->makeSound();
	wc->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wa;
	delete wc;
	return 0;
}
