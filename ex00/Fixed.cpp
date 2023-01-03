#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
	: _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_raw_bits = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_raw_bits = other.getRawBits();

	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _raw_bits;
}

void	Fixed::setRawBits(int const raw)
{
	_raw_bits = raw;
}
