#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command - ADD, SEARCH or EXIT: ";
        if (!std::getline(std::cin, cmd))
        {
            std::cout << std::endl;
            break;
        }
        if (cmd.empty()) 
            continue;

        if (cmd == "ADD")
            pb.promptAddContact();
        else if (cmd == "SEARCH")
            pb.promptIndexAndDisplay();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Command not found!" << std::endl;
    }
    return 0;
}