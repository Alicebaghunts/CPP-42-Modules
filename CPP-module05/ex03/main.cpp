#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

#define SAGE_GREEN  "\033[38;2;163;177;138m"
#define DUSTY_BLUE  "\033[38;2;109;130;153m"
#define SOFT_PURPLE "\033[38;2;150;120;170m"
#define RESET       "\033[0m"

int main()
{
    Intern someRandomIntern;
    AForm *form;

    std::cout << SOFT_PURPLE
              << "\n--------------- Intern Factory Test ---------------\n"
              << RESET << std::endl;

    std::cout << DUSTY_BLUE << "[Robotomy Request]" << RESET << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        std::cout << SAGE_GREEN << *form << RESET << std::endl;
        Bureaucrat boss("Boss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n" << DUSTY_BLUE << "[Shrubbery Creation]" << RESET << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form)
    {
        std::cout << SAGE_GREEN << *form << RESET << std::endl;
        Bureaucrat gardener("Gardener", 145);
        gardener.signForm(*form);
        gardener.executeForm(*form);
        delete form;
    }

    std::cout << "\n" << DUSTY_BLUE << "[Presidential Pardon]" << RESET << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Arthur");
    if (form)
    {
        std::cout << SAGE_GREEN << *form << RESET << std::endl;
        Bureaucrat president("President", 1);
        president.signForm(*form);
        president.executeForm(*form);
        delete form;
    }

    std::cout << "\n" << DUSTY_BLUE << "[Invalid Form]" << RESET << std::endl;
    form = someRandomIntern.makeForm("coffee", "Bob");
    if (form)
        delete form;

    std::cout << SOFT_PURPLE
              << "\n--------------- End of Test ---------------\n"
              << RESET;

    return 0;
}