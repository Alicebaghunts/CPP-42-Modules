#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (true)
	{
        std::cout << "Enter command - ADD, SEARCH or EXIT: ";
        std::getline(std::cin, cmd);

        if (cmd == "ADD")
            pb.promptAddContact();
        else if (cmd == "SEARCH")
            pb.promptIndexAndDisplay();
        else if (cmd == "EXIT")
            break;
    }
    return 0;
}