#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

# define F_NAME 1
# define L_NAME 2
# define N_NAME 3
# define P_NUMBER 4
# define D_SECRET 5

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
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
  public:
	void setContact(const std::string &fn, const std::string &ln,
		const std::string &nn, const std::string &pn, const std::string &ds);
	std::string getField(Field field) const;
};

#endif