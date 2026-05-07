#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(Fixed const& other) : _value(other._value) {}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	if (this != &rhs)
		_value = rhs._value;
	return *this;
}

Fixed::~Fixed(void) {}

Fixed::Fixed(int const i) : _value(i << _fractionalBits) {}

Fixed::Fixed(float const f) : _value(static_cast<int>(roundf(f * (1 << _fractionalBits)))) {}

int Fixed::getRawBits(void) const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw; }

float Fixed::toFloat(void) const { return static_cast<float>(_value) / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return _value >> _fractionalBits; }
