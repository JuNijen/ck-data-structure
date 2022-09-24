#pragma once
#include <iostream>

class Shape
{
	int m_color;

public:
	Shape() {};
	~Shape() {};

	void rotate(double r);
	void move(int x, int y);
	void fillColor(int c) { m_color = c; };
	int getColor() { return  m_color; };

	virtual void draw() = 0;
	virtual double area() = 0;
};