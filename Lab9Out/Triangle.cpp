#include "Triangle.h"
#include "graph1.h"
#include <cmath>

Triangle::Triangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
}

Triangle::Triangle(GenPoint a, GenPoint b, GenPoint c, Color color)
{
	// Validate the data of GenPoint a
	if (a.getX() < 0) {
		this->a.setPoint(0, a.getY());
	}
	else if (a.getX() > 639) {
		this->a.setPoint(639, a.getY());
	}
	else if (a.getY() < 0) {
		this->a.setPoint(a.getX(), 0);
	}
	else if (a.getY() > 399) {
		this->a.setPoint(a.getX(), 399);
	}
	else {
		this->a = a;
	}

	// Validate the data of GenPoint b
	if (b.getX() < 0) {
		this->b.setPoint(0, b.getY());
	}
	else if (b.getX() > 639) {
		this->b.setPoint(639, b.getY());
	}
	else if (b.getY() < 0) {
		this->b.setPoint(b.getX(), 0);
	}
	else if (b.getY() > 399) {
		this->b.setPoint(b.getX(), 399);
	}
	else {
		this->b = b;
	}

	// Validate the data of GenPoint c
	if (c.getX() < 0) {
		this->c.setPoint(0, c.getY());
	}
	else if (c.getX() > 639) {
		this->c.setPoint(639, c.getY());
	}
	else if (c.getY() < 0) {
		this->c.setPoint(c.getX(), 0);
	}
	else if (c.getY() > 399) {
		this->c.setPoint(c.getX(), 399);
	}
	else {
		this->c = c;
	}

	this->color = color;
}

void Triangle::setPoints(GenPoint a, GenPoint b, GenPoint c)
{
	// Validate the data of GenPoint a
	if (a.getX() < 0) {
		this->a.setPoint(0, a.getY());
	}
	else if (a.getX() > 639) {
		this->a.setPoint(639, a.getY());
	}
	else if (a.getY() < 0) {
		this->a.setPoint(a.getX(), 0);
	}
	else if (a.getY() > 399) {
		this->a.setPoint(a.getX(), 399);
	}
	else {
		this->a = a;
	}

	// Validate the data of GenPoint b
	if (b.getX() < 0) {
		this->b.setPoint(0, b.getY());
	}
	else if (b.getX() > 639) {
		this->b.setPoint(639, b.getY());
	}
	else if (b.getY() < 0) {
		this->b.setPoint(b.getX(), 0);
	}
	else if (b.getY() > 399) {
		this->b.setPoint(b.getX(), 399);
	}
	else {
		this->b = b;
	}

	// Validate the data of GenPoint c
	if (c.getX() < 0) {
		this->c.setPoint(0, c.getY());
	}
	else if (c.getX() > 639) {
		this->c.setPoint(639, c.getY());
	}
	else if (c.getY() < 0) {
		this->c.setPoint(c.getX(), 0);
	}
	else if (c.getY() > 399) {
		this->c.setPoint(c.getX(), 399);
	}
	else {
		this->c = c;
	}
}

double Triangle::getArea()
{
	double s,side1,side2,side3, area;
	side1 = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	side2 = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
	side3 = sqrt(pow(a.getX() - c.getX(), 2) + pow(a.getY() - c.getY(), 2));

	s = (side1 + side2 + side3) / 2.0;

	area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
	return area;
}

double Triangle::getPerimeter()
{
	double p = 0.0;
	double lines[3] = { 0.0 };

	// Calculate the length of each line with euclid's distance eqtn
	lines[0] = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	lines[1] = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
	lines[2] = sqrt(pow(a.getX() - c.getX(), 2) + pow(a.getY() - c.getY(), 2));

	// Sum up the length of each of the 3 lines
	for (int i = 0; i < 3; i++) {
		p += lines[i];
	}

	return p;
}

void Triangle::print()
{
	int x = 200;
	int y = 412;
	int lh = 12; // Line height
	gout << setPos(0, 400) << "-----------------------------------------------------------"
		<< "------------------" << endg;
	gout << setPos(x, y) << "Shape info follows for: Triangle" << endg;
	gout << setPos(x, y + lh) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(x, y + 2 * lh) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(x, y + 3 * lh) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(x, y + 4 * lh) << "Area: " << setPrecision(2) << getArea() << endg;
	gout << setPos(x, y + 5 * lh) << "Perimeter: " << setPrecision(2) << getPerimeter() << endg;
}

void Triangle::draw()
{
	int line = 0;
	line = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 2);
	::setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	line = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 2);
	::setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	line = drawLine(c.getX(), c.getY(), a.getX(), a.getY(), 2);
	::setColor(line, color.getRed(), color.getGreen(), color.getBlue());
}
