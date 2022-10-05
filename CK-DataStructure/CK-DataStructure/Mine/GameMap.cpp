#include <iostream>
#include "GameMap.h"
using namespace std;


void GameMap::setMine(int mineNum)
{
	m_mineNum = mineNum;
	for (int i = 0; i < mineNum; i++) {
		int x, y;
		do {
			x = rand() % m_width;
			y = rand() % m_height;
		} while (m_map[y][x].getTileNum() == MINE);
		m_map[y][x].setTileNum(MINE);
		updateTile(x, y);
	}
}

// 지뢰 주변 타일의 숫자를 update 한다. (x, y) ==> 지뢰가 설치가 되어있는 위치
void GameMap::updateTile(int x, int y)
{
	for (int cury = y - 1; cury <= y + 1; cury++) {
		for (int curx = x - 1; curx <= x + 1; curx++) {
			// curx, cury 위치가 게임맵의 범위를 벗어난 경우 ==> nothing
			if (curx < 0 || curx > m_width - 1 || cury < 0 || cury > m_height - 1)
				continue;
			// (curx, cury) == (x, y) 인경우 ==> 이미 지뢰가 설치가 되어 있음 ==> nothing
			if (curx == x && cury == y)
				continue;
			int curTileNum = m_map[cury][curx].getTileNum();
			if (curTileNum != MINE)
				m_map[cury][curx].setTileNum(curTileNum + 1);
		}
	}
}

int GameMap::openTile(int x, int y)
{
	Tile& curTile = m_map[y][x];

	// 맵의 범위를 벗어났거나 이미 오픈한 타일은 그대로 둔다.
	if (x < 0 || x > m_width - 1 || y < 0 || y > m_height - 1 || curTile.isTileOpened())
	{
		return -2;
	}

	// (x, y)에 지뢰가 있는 경우 ==> 모든 타일을 오픈
	if (curTile.getTileNum() == MINE) 
	{
		openAllTile();
		return -1;
	}

	// (x, y)타일이 아직 오픈하지 않은 타일이면
	if (!curTile.isTileOpened()) 
	{
		curTile.setTileOpened(true);

		if (curTile.getTileNum() == ZERO)
		{
			for (int posX = -1; posX < 2; posX++) 
			{
				for (int posY = -1; posY < 2; posY++)
				{
					// 자기 자신일 경우에는 continue 처리 해 주는 편이 좋다!
					openTile(x + posX, y + posY);
				}
			}
		}
		m_openTileNum++;
		return m_openTileNum;
	}

	return 0;
}

void GameMap::openAllTile()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_height; x++) 
		{
			m_map[y][x].setTileOpened(true);
		}
	}
}


void GameMap::draw()
{
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			m_map[y][x].draw();
		}
		cout << endl;
	}
}
