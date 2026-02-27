#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
    Contact contacts[8];
    int nextIndex;
    int totalContacts;

public:
    PhoneBook();

	int getTotalContacts() const;
    void addContact(const Contact &c);
    void displayContacts() const;
    void displayContactDetails(int index) const;

	void promptAddContact();
	void promptIndexAndDisplay() const;
};

#endif