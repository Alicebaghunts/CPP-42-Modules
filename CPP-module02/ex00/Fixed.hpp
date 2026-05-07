#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed(void);
	Fixed(Fixed const& other);
	Fixed& operator=(Fixed const& rhs);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
