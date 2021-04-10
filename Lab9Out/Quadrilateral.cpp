#include "Quadrilateral.h"
#include "graph1.h"
#include <cmath>

Quadrilateral::Quadrilateral()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);
}

Quadrilateral::Quadrilateral(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
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

	// Validate the data of GenPoint d
	if (d.getX() < 0) {
		this->d.setPoint(0, d.getY());
	}
	else if (d.getX() > 639) {
		this->d.setPoint(639, d.getY());
	}
	else if (d.getY() < 0) {
		this->d.setPoint(d.getX(), 0);
	}
	else if (d.getY() > 399) {
		this->d.setPoint(d.getX(), 399);
	}
	else {
		this->d = d;
	}
	this->color = color;
}

void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
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

	// Validate the data of GenPoint d
	if (d.getX() < 0) {
		this->d.setPoint(0, d.getY());
	}
	else if (d.getX() > 639) {
		this->d.setPoint(639, d.getY());
	}
	else if (d.getY() < 0) {
		this->d.setPoint(d.getX(), 0);
	}
	else if (d.getY() > 399) {
		this->d.setPoint(d.getX(), 399);
	}
	else {
		this->d = d;
	}
}

double Quadrilateral::getPerimeter()
{
	double p = 0.0;
	double lines[4] = { 0.0 };

	// Calculate the length of each line with euclid's distance eqtn
	lines[0] = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	lines[1] = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
	lines[2] = sqrt(pow(d.getX() - c.getX(), 2) + pow(d.getY() - c.getY(), 2));
	lines[3] = sqrt(pow(a.getX() - d.getX(), 2) + pow(a.getY() - d.getY(), 2));

	// Sum up the length of each of the 4 lines
	for (int i = 0; i < 4; i++) {
		p += lines[i];
	}

	return p;
}

void Quadrilateral::print()
{
	int x = 200;
	int y = 412;
	int lh = 12; // Line height
	gout << setPos(0, 400) << "-----------------------------------------------------------"
		<< "------------------" << endg;
	gout << setPos(x, y) << "Shape info follows for : Quadrilateral" << endg;
	gout << setPos(x, y + lh) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(x, y + 2 * lh) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(x, y + 3 * lh) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(x, y + 4 * lh) << "Point d: (" << d.getX() << "," << d.getY() << ")" << endg;
	gout << setPos(x, y + 5 * lh) << "Perimeter: " << setPrecision(2) << getPerimeter() << endg;
}

void Quadrilateral::draw()
{
	int line = 0;
	line = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 2);
	::setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	line = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 2);
	::setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	line = drawLine(c.getX(), c.getY(), d.getX(), d.getY(), 2);
	::setColor(line, color.getRed(), color.getGreen(), color.getBlue());

	line = drawLine(d.getX(), d.getY(), a.getX(), a.getY(), 2);
	::setColor(line, color.getRed(), color.getGreen(), color.getBlue());
}
