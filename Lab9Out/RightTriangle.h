#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle
{

public:

	RightTriangle();
	RightTriangle(GenPoint vertex, int height, int base, Color color);
	void print();
};

#endif


