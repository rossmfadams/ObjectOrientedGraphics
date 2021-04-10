#include "Shape.h"

Shape::Shape()
{
	color.setColor(0, 0, 0);
}

Color Shape::getColor()
{
	return color;
}

void Shape::setColor(Color color)
{
	this->color = color;
}
