#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point	a;
	Point	b(50.5, 100.45);
	Point	c(100.45, 50.9);
	Point	point(50.5, 100.43);

	std::cout << bsp(a, b, c, point) << "\n\n" << std::endl;
	b = c;
	std::cout << bsp(a, b, c, point) << "\n\n" << std::endl;
	return 0;
}
