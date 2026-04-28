#include <iostream>
#include <cmath>
#include "Point.hpp"
#include "Fixed.hpp"

// which side of the line is point on
// vector u = point - vertex2
// vector v = vertex 1 - vertex2
static Fixed	sign(Point point, Point vertex1, Point vertex2)
{
	Fixed	u = (point.getX() - vertex2.getX()) * (vertex1.getY() - vertex2.getY());
	Fixed	v = (vertex1.getX() - vertex2.getX()) * (point.getY() - vertex2.getY());

	return (u - v);

}
// return ((point.getX() - vertex2.getX()) * (vertex1.getY() - vertex2.getY()) - (vertex1.getX() - vertex2.getX()) * (point.getY() - vertex2.getY()));

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	pab = sign(point, a, b);
	Fixed	pbc = sign(point, b, c);
	Fixed	pca = sign(point, c, a);

	bool	outside = (pab <= 0) || (pbc <= 0) || (pca <= 0);
	bool	inside = (pab > 0) || (pbc > 0) || (pca > 0);

	return (!(outside && inside));
}