#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(Fixed& other);
	~Fixed();
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					raw_value;
	static const int	fractional_bits;
};

#endif
