#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm *(*FormCreator)(const std::string &target);

AForm *createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *createPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() { }

Intern::Intern(const Intern &) { }

Intern &Intern::operator=(const Intern &) {
    return *this;
}

Intern::~Intern() { }

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    struct FormEntry
	{
        const char *name;
        FormCreator creator;
    };

    const FormEntry table[] = {
		{ "shrubbery creation", createShrubbery },
		{ "robotomy request", createRobotomy },
		{ "presidential pardon", createPardon }
    };

    for (int i = 0; i < 3; ++i)
    {
		if (formName == table[i].name)
		{
			AForm *form = table[i].creator(target);

			std::cout << "Intern creates " << table[i].name << std::endl;
			return form;
		}
    }
    std::cerr << "Error: unknown form ('" << formName << "'" << std::endl;
    return 0;
}