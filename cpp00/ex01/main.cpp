#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    nextIndex = 0;
    totalContacts = 0;
}

int main()
{
    PhoneBook pb;
    std::string command;

    while (true)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            // հարցնում ես 5 field
            // ստեղծում ես Contact
            // pb.addContact(...)
        }
        else if (command == "SEARCH")
        {
            // pb.displayContacts()
            // index հարցնում ես
            // pb.searchContact(index)
        }
        else if (command == "EXIT")
            break;
    }
}