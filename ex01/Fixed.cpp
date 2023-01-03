#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
	: _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
	: _raw_bits(raw)
{
	std::cout << "Int constructor called" << std::endl;
}

/**
 * float 을 int 형으로 변경하는 법 알아보기
 */
Fixed::Fixed(const float raw)
	: _raw_bits(raw)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	//_raw_bits = other._raw_bits;
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
	return _raw_bits;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& rhs)
{
	std::cout << rhs.getRawBits();

	return out;
}

int	Fixed::getRawBits(void) const
{
	return _raw_bits;
}

//void	Fixed::setRawBits(int const raw)
//{
//	_raw_bits = raw;
//}
