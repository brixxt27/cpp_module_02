#include "Point.hpp"

static float	GetEquationOfTheLine(Point const p1, Point const p2, Point const other)
{
	return (other.GetX().toFloat() - p1.GetX().toFloat()) * (p1.GetY().toFloat() - p2.GetY().toFloat()) / (p1.GetX().toFloat() - p2.GetX().toFloat()) + p1.GetY().toFloat() - other.GetY().toFloat();
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	float	la = GetEquationOfTheLine(b, c, a);
	float	lb = GetEquationOfTheLine(c, a, b);
	float	lc = GetEquationOfTheLine(a, b, c);
	float	point_la = GetEquationOfTheLine(b, c, point);
	float	point_lb = GetEquationOfTheLine(c, a, point);
	float	point_lc = GetEquationOfTheLine(a, b, point);

	return (la * point_la > 0 && lb * point_lb > 0 && lc * point_lc > 0);
}
