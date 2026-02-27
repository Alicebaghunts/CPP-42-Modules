#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command ➤ \033[0;36mADD, SEARCH or EXIT → \033[0m";
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
            std::cout << "\033[0;30mCommand not found! \033[0m" << std::endl;
    }
    return 0;
}