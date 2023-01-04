#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_raw_bits;
	static const int	_fractional_bits;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& rhs);

#endif
