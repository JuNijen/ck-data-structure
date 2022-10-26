#pragma once
#include "GameObject.h"

class Plane : public GameObject 
{
public:
	Plane(int x, int y, wchar_t* img) : GameObject(x, y, img) {};
	~Plane() {};

	void Update() override;
};