#pragma once
#include "Tile.h"

class GameMap 
{
protected:
	int m_width;
	int m_height;
	GameObject** m_map;

public:
	static int mapWidth;
	static int mapHeight;

	GameMap();
	~GameMap();

	void InitMap();
	GameObject getTile(int x, int y) const { return m_map[y][x]; };
	void SetTile(int x, int y, GameObject obj) { m_map[y][x] = obj; }
	void Draw();
};