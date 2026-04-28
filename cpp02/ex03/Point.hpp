#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point(const float fp1, const float fp2);
		Point(const Point &copy);
		Point &operator=(const Point &op);
		~Point();

		const Fixed	getX() const;
		const Fixed	getY() const;

	private:
		const Fixed	x;
		const Fixed	y;
};


#endif
