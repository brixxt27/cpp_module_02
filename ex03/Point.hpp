#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point& rhs);
	~Point();
	
	const Fixed&	GetX() const;
	const Fixed&	GetY() const;

private:
	const Fixed	_x;
	const Fixed	_y;

	void	PrintErrorCopyAssignmnet() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
