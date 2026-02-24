#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
  public:
    enum	Field
	{
		FIRST_NAME,
		LAST_NAME,
		NICKNAME,
		PHONE_NUMBER,
		DARKEST_SECRET
	};
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
  public:
	void setContact(const std::string &fn, const std::string &ln,
		const std::string &nn, const std::string &pn, const std::string &ds);
	std::string getField(Field field) const;
	// std::string getFirstName() const;
	// std::string getLastName() const;
	// std::string getNickname() const;
	// std::string getPhoneNumber() const;
	// std::string getDarkestSecret() const;
};

#endif