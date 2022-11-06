#pragma once
#include "LarvaGameTile.h"


class GameMap
{
private:
	int m_width;
	int m_height;
	GameObject** m_map;

public:
	GameMap(int width, int height);
	~GameMap();

	void InitMap();
	void Draw();
	int GetWidth() { return m_width; };
	int GetHeight() { return m_height; };
	GameObject GetTile(int x, int y) const { return m_map[y][x]; };
};