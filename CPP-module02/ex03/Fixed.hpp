#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _value;
	static const int _fractionalBits = 8;

public:
	Fixed(void);
	Fixed(Fixed const& other);
	Fixed& operator=(Fixed const& rhs);
	~Fixed(void);

	Fixed(int const i);
	Fixed(float const f);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

#endif
