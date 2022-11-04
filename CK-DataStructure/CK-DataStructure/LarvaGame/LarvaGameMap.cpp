#include "LarvaGameMap.h"


GameMap::GameMap(int width, int height) : m_width(width), m_height(height)
{
	m_map = nullptr;
	m_map = new GameObject*[m_height];

	for (int count = 0; count < m_height; count++) 
	{
		m_map[count] = new Tile[m_width];
	}
	
	InitMap();
}

GameMap::~GameMap() 
{
	for (int count = 0; count < m_height; count++)
	{
		delete m_map[count];
	}
	delete[] m_map;
}

void GameMap::InitMap() 
{
	for (int y = 0; y < m_height; y++) 
	{
		for (int x = 0; x < m_width; x++)
		{
			if (x == 0 || x == m_width - 1 || y == 0 || y == m_height - 1) // if it is edge
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
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_height; x++)
		{
			m_map[y][x].Draw();
		}
	}
}