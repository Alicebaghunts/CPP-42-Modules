#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void	testDeepCopy(void)
{
	Dog	dogA;
	Dog	dogB;

	std::cout << "\n>>> DEEP COPY TEST <<<\n" << std::endl;
	dogA.setIdea(0, "I am dog A - I love bones");
	dogB.setIdea(0, "I am dog B - I love cats");
	std::cout << "Before assignment:" << std::endl;
	std::cout << "dogA idea[0] = " << dogA.getIdea(0) << std::endl;
	std::cout << "dogB idea[0] = " << dogB.getIdea(0) << std::endl;
	dogB = dogA;
	std::cout << "\nAfter dogB = dogA:" << std::endl;
	std::cout << "dogA idea[0] = " << dogA.getIdea(0) << std::endl;
	std::cout << "dogB idea[0] = " << dogB.getIdea(0) << std::endl;
	dogA.setIdea(0, "This is changed in dogA only");
	std::cout << "\nAfter modifying dogA:" << std::endl;
	std::cout << "dogA idea[0] = " << dogA.getIdea(0) << std::endl;
	std::cout << "dogB idea[0] = " << dogB.getIdea(0) << std::endl;
	std::cout << "\n>>> DEEP COPY TEST FINISHED <<<\n" << std::endl;
}

int	main(void)
{
	std::cout << "Creating and filling array of Animal objects...\n" << std::endl;

	AAnimal *animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "Making sounds:\n";
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	std::cout << "\nDeleting every Animal...\n" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << "\nCreating single Dog and Cat...\n" << std::endl;
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	testDeepCopy();

	std::cout << "\n=== All tests finished ===\n" << std::endl;
	return (0);
}