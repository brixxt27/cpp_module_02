#include <cmath>
#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

std::ostream&	operator<<(std::ostream& out, const Fixed& rhs)
{
	out << rhs.toFloat();

	return out;
}

Fixed::Fixed()
	: _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
	: _raw_bits(raw * (1 << _fractional_bits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw)
	: _raw_bits(static_cast<int>(roundf(raw * (1 << _fractional_bits))))
{
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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _raw_bits;
}

void	Fixed::setRawBits(int const raw)
{
	_raw_bits = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_raw_bits) / (1 << _fractional_bits);
}

int	Fixed::toInt(void) const
{
	return _raw_bits >> _fractional_bits;
}

/**
 * Comparison operators
 */

bool	Fixed::operator>(const Fixed& rhs) const
{
	return toFloat() > rhs.toFloat();
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return toFloat() < rhs.toFloat();
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return toFloat() >= rhs.toFloat();
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return toFloat() <= rhs.toFloat();
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return toFloat() == rhs.toFloat();
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return toFloat() != rhs.toFloat();
}

/**
 * Arithmetic operators
 */

float	Fixed::operator+(const Fixed& rhs) const
{

	return toFloat() + rhs.toFloat();
}

float	Fixed::operator-(const Fixed& rhs) const
{
	return toFloat() - rhs.toFloat();
}

float	Fixed::operator*(const Fixed& rhs) const
{
	return toFloat() * rhs.toFloat();
}

float	Fixed::operator/(const Fixed& rhs) const
{
	return toFloat() / rhs.toFloat();
}

/**
 * Increment / Decrement (pre- , post- )operators
 */

Fixed&	Fixed::operator++()
{
	++_raw_bits;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++(*this);
	return temp;
}

Fixed&	Fixed::operator--()
{
	--_raw_bits;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--(*this);
	return temp;
}

/**
 * Static member functions
 */

Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs)
{
	return (lhs.toFloat() > rhs.toFloat()) ? rhs : lhs;
}

Fixed&	Fixed::max(Fixed& lhs, Fixed& rhs)
{
	return (lhs.toFloat() < rhs.toFloat()) ? rhs : lhs;

}

Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.toFloat() > rhs.toFloat()) ? const_cast<Fixed&>(rhs) : const_cast<Fixed&>(lhs);
}

Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.toFloat() < rhs.toFloat()) ? const_cast<Fixed&>(rhs) : const_cast<Fixed&>(lhs);
}
