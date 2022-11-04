#pragma once
#include "LarvaGameObject.h"
#include "LarvaGameMap.h"
#include <windows.h>
#include <conio.h>


class Snake : public GameObject
{
private:
	int m_mapWidth;
	int m_mapHeight;
	int m_delay;

public:
	Snake(int x, int y, wchar_t* img, int delay = 100) : GameObject(x, y, img), m_delay(delay) {};
	Snake() { };
	~Snake() {};

	void Update() override;
	void Draw() override;

	void SetMap(int width, int height) { m_mapWidth = width, m_mapHeight = height; };
	bool Crushed();
};