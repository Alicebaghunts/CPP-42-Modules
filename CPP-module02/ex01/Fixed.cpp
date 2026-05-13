#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;

	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;

	this->_value = roundf(f * (1 << this->_fractionalBits));
}

Fixed::Fixed(Fixed const& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->_value = rhs._value;

	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/*
	Fixed-point -> float
	raw / 256
	960 / 256 = 3.75
*/
float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->_fractionalBits);
}

/*
	Fixed-point -> integer
	1280 / 256 = 5
*/
int Fixed::toInt(void) const
{
	return this->_value >> this->_fractionalBits;
}

/*
	<< operator overload
	std::cout << fixed;
	print float representation
*/
std::ostream& operator<<(std::ostream& o, Fixed const& rhs)
{
	o << rhs.toFloat();

	return o;
}