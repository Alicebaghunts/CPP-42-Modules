#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Value not found";
	}
};

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	typedef typename T::const_iterator const_iterator;

	const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif
