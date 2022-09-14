#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double m_radius;

public:
	Circle(double r) : m_radius(r) {}
	Circle() {};

	double getDiameter() { return m_radius; }

	void draw() override;
	double area() override;
};

