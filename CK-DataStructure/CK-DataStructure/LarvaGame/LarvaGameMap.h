#pragma once
#include "LarvaGameTile.h"


//class GameMap
//{
//protected:
//	int m_width;
//	int m_height;
//	GameObject** m_map;
//
//public:
//	static int mapWidth;
//	static int mapHeight;
//
//	GameMap();
//	~GameMap();
//
//	void InitMap();
//	GameObject getTile(int x, int y) const { return m_map[y][x]; };
//	void SetTile(int x, int y, GameObject obj) { m_map[y][x] = obj; }
//	void Draw();
//};

class GameMap 
{
private:
	int m_width;
	int m_height;
	GameObject m_item;
	GameObject** m_map;

public:
	GameMap(int width, int height);
	~GameMap();

	void InitMap();
	void Draw();

	//void SetTile(int x, int y, GameObject obj) { m_map[y][x] = obj; }
	void SetItem(GameObject obj) { m_item = obj; };

	int GetWidth() { return m_width; };
	int GetHeight() { return m_height; };
	GameObject GetTile(int x, int y) const { return m_map[y][x]; };
	GameObject getItem() { return m_item; };
};