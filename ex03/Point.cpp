#include "Point.hpp"

Point::Point()
	: _x(0)
	, _y(0)
{
	std::cout << "Point: Default constructor called" << std::endl;
}

Point::Point(const float x, const float y)
	: _x(x)
	, _y(y)
{
	std::cout << "Point: Float constructor called" << std::endl;
}

Point::Point(const Point& other)
	: _x(other._x)
	, _y(other._y)
{
	std::cout << "Point: Copy constructor called" << std::endl;
}

Point&	Point::operator=(const Point& rhs)
{
	std::cout << "Point: Copy assignment operator called" << std::endl;

	rhs.PrintErrorCopyAssignmnet();
	return (*this);
}

Point::~Point()
{
	std::cout << "Point: Destructor called" << std::endl;
}

const Fixed&	Point::GetX() const
{
	return _x;
}

const Fixed&	Point::GetY() const
{
	return _y;
}

void	Point::PrintErrorCopyAssignmnet() const
{
	std::cout << "Point: Copy assignment operator can't be used!" << std::endl;
}
