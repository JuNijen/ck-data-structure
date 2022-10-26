#pragma once
#include "GameObject.h"

class Tile : public GameObject 
{
public:
	Tile() {};
	Tile(int x, int y, wchar_t* img) : GameObject(x, y, img) {};
	~Tile() {};
};