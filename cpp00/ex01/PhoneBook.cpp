#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	nextIndex = 0;
	totalContacts = 0;
}

int PhoneBook::getTotalContacts() const
{
    return totalContacts;
}

static std::string formatField(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool isNumber(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

void   PhoneBook::promptAddContact()
{
    Contact	contact;

	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_num;
	std::string dark_sec;

	std::cout << "First Name : ";
	std::getline(std::cin, first_name);
	std::cout << "Last Name : ";
	std::getline(std::cin, last_name);
	std::cout << "Nick Name : ";
	std::getline(std::cin, nick_name);
	std::cout << "Phone Number : ";
	std::getline(std::cin, phone_num);
	std::cout << "Darkest Secret : ";
	std::getline(std::cin, dark_sec);

	if (first_name.empty() || last_name.empty() || nick_name.empty()
		|| phone_num.empty() || dark_sec.empty())
	{
		std::cout << "All fields must be non-empty!" << std::endl;
		return ;
	}
		
	contact.setContact(first_name, last_name, nick_name, phone_num, dark_sec);
	addContact(contact);
}

void PhoneBook::promptIndexAndDisplay() const
{
    displayContacts();

    if (totalContacts == 0)
        return;

    std::string idx_str;
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, idx_str);
    if (idx_str.empty())
        return;
    for (size_t i = 0; i < idx_str.length(); ++i)
    {
        if (idx_str[i] < '0' || idx_str[i] > '9')
        {
            std::cout << "Invalid input!" << std::endl;
            return ;
        }
    }
    int idx = atoi(idx_str.c_str());
    if (idx < 0 || idx >= getTotalContacts())
    {
        std::cout << "Invalid index!" << std::endl;
        return ;
    }
    displayContactDetails(idx);
}

void PhoneBook::addContact(const Contact &c)
{
    contacts[nextIndex] = c;

    nextIndex = (nextIndex + 1) % 8;

    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::displayContactDetails(int index) const
{
    std::cout << "First Name : "
        << contacts[index].getField(Contact::FIRST_NAME)<< std::endl;
    std::cout << "Last Name : "
        << contacts[index].getField(Contact::LAST_NAME) << std::endl;
    std::cout << "Nickname : "
        << contacts[index].getField(Contact::NICKNAME) << std::endl;
    std::cout << "Phone Number : "
        << contacts[index].getField(Contact::PHONE_NUMBER) << std::endl;
    std::cout << "Darkest Secret : "
        << contacts[index].getField(Contact::DARKEST_SECRET) << std::endl;
}


void PhoneBook::displayContacts() const
{
    if (totalContacts == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return ;
    }

    std::cout << std::setw(10) << "Index" << "|"
        << std::setw(10) << "First Name" << "|"
        << std::setw(10) << "Last Name" << "|"
        << std::setw(10) << "Nickname" << "|"
        << std::endl;

    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << std::setw(10) << i << "|"
            << std::setw(10) << formatField(contacts[i].getField(Contact::FIRST_NAME)) << "|"
            << std::setw(10) << formatField(contacts[i].getField(Contact::LAST_NAME)) << "|"
            << std::setw(10) << formatField(contacts[i].getField(Contact::NICKNAME))
            << std::endl;
    }
}
