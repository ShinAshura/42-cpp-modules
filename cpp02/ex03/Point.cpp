#include <iostream>
#include <cmath>
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{

}

Point::Point(const float fp1, const float fp2) : x(Fixed(fp1)), y(Fixed(fp2))
{

}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
	
}

Point	&Point::operator=(const Point &op)
{
	if (this == &op)
		return (*this);
	return (*this);
}

Point::~Point()
{

}

const Fixed	Point::getX() const
{
	return (this->x);
}

const Fixed	Point::getY() const
{
	return (this->y);
}
