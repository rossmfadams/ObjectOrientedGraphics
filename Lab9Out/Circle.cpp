#define _USE_MATH_DEFINES

#include "Circle.h"
#include <cmath>
#include "graph1.h"

Circle::Circle()
{
	radius = 0;
	center.setPoint(0, 0);
}

Circle::Circle(GenPoint center, int radius, Color c)
{
	// Validate the radius
	if (radius < 1) {
		this->radius = 1;
	}
	else {
		this->radius = radius;
	}

	// Validate the data of GenPoint center
	if (center.getX() < 0) {
		this->center.setPoint(0, center.getY());
	}
	else if (center.getX() > 639) {
		this->center.setPoint(639, center.getY());
	}
	else if (center.getY() < 0) {
		this->center.setPoint(center.getX(), 0);
	}
	else if (center.getY() > (400-this->radius)) {
		this->center.setPoint(center.getX(), (400 - this->radius));
	}
	else {
		this->center = center;
	}

	this->color = c;
}

void Circle::setCenter(GenPoint center)
{
	// Validate the data of GenPoint center
	if (center.getX() < 0) {
		this->center.setPoint(0, center.getY());
	}
	else if (center.getX() > 639) {
		this->center.setPoint(639, center.getY());
	}
	else if (center.getY() < 0) {
		this->center.setPoint(center.getX(), 0);
	}
	else if (center.getY() > (400 - this->radius)) {
		this->center.setPoint(center.getX(), (400 - this->radius));
	}
	else {
		this->center = center;
	}
}

void Circle::setRadius(int radius)
{
	// Validate the radius
	if (radius < 1) {
		this->radius = 1;
	}
	else {
		this->radius = radius;
	}
}

double Circle::getPerimeter()
{
	double circumference = 0.0;
	circumference = 2 * M_PI * radius;
	return circumference;
}

double Circle::getArea()
{
	double area = 0.0;
	area = pow(radius, 2) * M_PI;
	return area;
}

void Circle::print()
{
	int x = 200;
	int y = 412;
	int lh = 12; // Line height
	gout << setPos(0, 400) << "-----------------------------------------------------------"
		<< "------------------" << endg;
	gout << setPos(x, y) << "Shape info follows for : Circle" << endg;
	gout << setPos(x, y + lh) << "Center Point: (" << center.getX() << "," << center.getY() << ")" << endg;
	gout << setPos(x, y + 2 * lh) << "Radius: " << radius << endg;
	gout << setPos(x, y + 3 * lh) << "Perimeter: " << setPrecision(2) << getPerimeter() << endg;
}

void Circle::draw()
{
	int circle = 0;
	circle = drawCircle(radius, center.getX(), center.getY());
	::setColor(circle, color.getRed(), color.getGreen(), color.getBlue());
}
