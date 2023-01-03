#include <cmath>
#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
	: _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	_raw_bits = raw << 8;
}

Fixed::Fixed(const float raw)
{
	_raw_bits = roundf(raw * (1 << _fractional_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_raw_bits = other._raw_bits;

	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * 추가 구현 필요
 */
float	Fixed::toFloat(void) const
{
	return _raw_bits;
}

int	Fixed::toInt(void) const
{
	return _raw_bits >> 8;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& rhs)
{
	out << rhs.getRawBits();

	return out;
}

int	Fixed::getRawBits(void) const
{
	return _raw_bits >> 8;
}

//void	Fixed::setRawBits(int const raw)
//{
//	_raw_bits = raw;
//}
