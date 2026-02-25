#include "Contact.hpp"

void Contact::setContact(const std::string &first_name,
	const std::string &last_name, const std::string &nick_name,
	const std::string &phone_number, const std::string &darkest_secret)
{
	firstName = first_name;
	lastName = last_name;
	nickName = nick_name;
	phoneNumber = phone_number;
	darkestSecret = darkest_secret;
}

std::string Contact::getField(Field filed) const
{
	switch (filed)
	{
	case FIRST_NAME:
		return (firstName);
	case LAST_NAME:
		return (lastName);
	case NICKNAME:
		return (nickName);
	case PHONE_NUMBER:
		return (phoneNumber);
	case DARKEST_SECRET:
		return (darkestSecret);
	}
    return "";
}