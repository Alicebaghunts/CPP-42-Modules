#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(int const n) : _value(n << _fractionalBits)
{
}

Fixed::Fixed(float const f)
{
	_value = static_cast<int>(roundf(f * static_cast<float>(1 << _fractionalBits)));
}

Fixed::Fixed(Fixed const &other) : _value(other._value)
{
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_value = rhs._value;
	return (*this);
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value)
		/ static_cast<float>(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_value / (1 << _fractionalBits));
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return (this->_value > rhs._value);
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return (this->_value < rhs._value);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_value >= rhs._value);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_value <= rhs._value);
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return (this->_value == rhs._value);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_value != rhs._value);
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed result;

	result.setRawBits(this->_value + rhs._value);
	return (result);
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed result;

	result.setRawBits(this->_value - rhs._value);
	return (result);
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	Fixed result;
	long long const mul = static_cast<long long>(this->_value)
		* static_cast<long long>(rhs._value);

	result.setRawBits(static_cast<int>(mul / (1 << _fractionalBits)));
	return (result);
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	Fixed result;
	long long const num = static_cast<long long>(this->_value)
		* static_cast<long long>(1 << _fractionalBits);

	result.setRawBits(static_cast<int>(num / rhs._value));
	return (result);
}

Fixed &Fixed::operator++(void)
{
	this->_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	this->_value += 1;
	return (old);
}

Fixed &Fixed::operator--(void)
{
	this->_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	this->_value -= 1;
	return (old);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	if (&o && true)
		o << rhs.toFloat();
	return (o);
}
