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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;
	
	float	operator+(const Fixed& rhs) const;
	float	operator-(const Fixed& rhs) const;
	float	operator*(const Fixed& rhs) const;
	float	operator/(const Fixed& rhs) const;

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed&	min(Fixed& lhs, Fixed& rhs);
	static Fixed&	max(Fixed& lhs, Fixed& rhs);
	static Fixed&	min(const Fixed& lhs, const Fixed& rhs);
	static Fixed&	max(const Fixed& lhs, const Fixed& rhs);

private:
	int					_raw_bits;
	static const int	_fractional_bits;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& rhs);

#endif
