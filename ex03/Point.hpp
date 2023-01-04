#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float x, const float y);
	Point(const Fixed& other);
	Point& operator=(const Point& rhs);
	~Point();
	/**
	 * anything else useful
	*/

private:
	const Fixed	x;
	const Fixed	y;
	/**
	 * anything else useful
	*/
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
