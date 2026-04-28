#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main()
{
    // Point a(0.0f, 0.0f);
    // Point b(10.0f, 0.0f);
    // Point c(5.0f, 10.0f);

    // Point insidePoint(5.0f, 5.0f);
    // Point outsidePoint(10.0f, 10.0f);
    // Point edgePoint(5.0f, 0.0f);

    // std::cout << "insidePoint is inside triangle: " << (bsp(a, b, c, insidePoint) ? "YES" : "NO") << std::endl;
    // std::cout << "outsidePoint is inside triangle: " << (bsp(a, b, c, outsidePoint) ? "YES" : "NO") << std::endl;
    // std::cout << "edgePoint is inside triangle: " << (bsp(a, b, c, edgePoint) ? "YES" : "NO") << std::endl;


	// =====================================================================

	Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point inside(2.5f, 2.0f);
    Point inside2(1.5f, 2.0f);
    Point inside3(1.5f, 1.0f);
    Point outside(5.0f, 5.0f);
    Point onEdgeAB(2.5f, 0.0f);
    Point onEdgeBC(3.75f, 2.5f);
    Point onEdgeCA(1.25f, 2.5f);
    Point onVertexA(0.0f, 0.0f);
    Point barelyInside(2.5f, 0.1f);
    Point barelyOutside(2.5f, -0.1f);

    std::cout << "Point inside triangle: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point inside2 triangle: " << bsp(a, b, c, inside2) << std::endl;
    std::cout << "Point inside3 triangle: " << bsp(a, b, c, inside3) << std::endl;
    std::cout << "Point outside triangle: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Point on edge AB: " << bsp(a, b, c, onEdgeAB) << std::endl;
    std::cout << "Point on edge BC: " << bsp(a, b, c, onEdgeBC) << std::endl;
    std::cout << "Point on edge CA: " << bsp(a, b, c, onEdgeCA) << std::endl;
    std::cout << "Point on vertex A: " << bsp(a, b, c, onVertexA) << std::endl;
    std::cout << "Point just inside triangle: " << bsp(a, b, c, barelyInside) << std::endl;
    std::cout << "Point just outside triangle: " << bsp(a, b, c, barelyOutside) << std::endl;


	return (0);
}
