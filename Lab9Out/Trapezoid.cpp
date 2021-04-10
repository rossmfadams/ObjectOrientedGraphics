#include "Trapezoid.h"
#include "graph1.h"
#include <cmath>

Trapezoid::Trapezoid()
{
	Quadrilateral::Quadrilateral();
}

Trapezoid::Trapezoid(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	Quadrilateral::setPoints(a, b, c, d);
	Quadrilateral::setColor(color);
}

void Trapezoid::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{
	Quadrilateral::setPoints(a, b, c, d);
}

double Trapezoid::getArea()
{
	double base1, base2, height, area;
	base1 = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	base2 = sqrt(pow(d.getX() - c.getX(), 2) + pow(d.getY() - c.getY(), 2));
	height = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));

	area = 0.5 * (base1 + base2) * height;

	return area;
}

void Trapezoid::print()
{
	gout << setPos(0, 12) << "Trapezoid Information" << endg;
	gout << setPos(0, 24) << "Area: " << setPrecision(2) <<
		Trapezoid::getArea() << endg;

	Quadrilateral::print();
}
