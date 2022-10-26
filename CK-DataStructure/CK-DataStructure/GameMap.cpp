#include "GameMap.h"

GameMap::GameMap() : m_width(mapWidth), m_height(mapHeight) 
{
	m_map = nullptr;
	m_map = new GameObject*[mapHeight];

	for (int count = 0; count < mapHeight; count++) 
	{
		m_map[count] = new Tile[mapWidth];
	}
	
	InitMap();
}

GameMap::~GameMap() 
{
	for (int count = 0; count < mapHeight; count++)
	{
		delete m_map[count];
	}
}

void GameMap::InitMap() 
{
	for (int y = 0; y < mapHeight; y++) 
	{
		for (int x = 0; x < mapWidth; x++)
		{
			if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight - 1) // if it is edge
			{
				m_map[y][x] = Tile(x, y, (wchar_t*)L"бс");
			}
			else 
			{
				m_map[y][x] = Tile(x, y, (wchar_t*)L" ");
			}
		}
	}
}

void GameMap::Draw() 
{
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapHeight; x++)
		{
			m_map[y][x].Draw();
		}
	}
}