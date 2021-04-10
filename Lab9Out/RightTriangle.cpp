#include "RightTriangle.h"
#include "graph1.h"

RightTriangle::RightTriangle()
{
	Triangle::Triangle();
}

RightTriangle::RightTriangle(GenPoint vertex, int height, int base, Color color)
{
	a.setPoint(vertex.getX(),vertex.getY());
	b.setPoint(vertex.getX(), vertex.getY() - height);
	c.setPoint(vertex.getX() + base, vertex.getY());

	Triangle::setPoints(a, b, c);
	Triangle::setColor(color);
}

void RightTriangle::print()
{
	gout << setPos(0, 12) << "Right Triangle" << endg;

	Triangle::print();
}
