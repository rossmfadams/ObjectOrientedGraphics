#include "GenRectangle.h"
#include <cmath>
#include "graph1.h"

GenRectangle::GenRectangle()
{
	Quadrilateral::Quadrilateral();
}

GenRectangle::GenRectangle(GenPoint ul, GenPoint lr, Color color)
{
	a.setPoint(ul.getX(), ul.getY());
	c.setPoint(lr.getX(), lr.getY());
	b.setPoint(lr.getX(), ul.getY());
	d.setPoint(ul.getX(), lr.getY());

	Quadrilateral::setPoints(a, b, c, d);
	Quadrilateral::setColor(color);
}

void GenRectangle::setPoints(GenPoint ul, GenPoint lr)
{
	a.setPoint(ul.getX(), ul.getY());
	c.setPoint(lr.getX(), lr.getY());
	b.setPoint(lr.getX(), ul.getY());
	d.setPoint(ul.getX(), lr.getY());

	Quadrilateral::setPoints(a, b, c, d);
}

double GenRectangle::getArea()
{
	double area = 0.0;
	double length = 0.0;
	double width = 0.0;

	length = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	width = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));

	area = length * width;

	return area;
}

void GenRectangle::print()
{
	gout << setPos(0, 12) << "Rectangle Information" << endg;
	gout << setPos(0, 24) << "Area: " << setPrecision(2) <<
		getArea() << endg;

	Quadrilateral::print();
}
