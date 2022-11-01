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

// ���� �ֺ� Ÿ���� ���ڸ� update �Ѵ�. (x, y) ==> ���ڰ� ��ġ�� �Ǿ��ִ� ��ġ
void GameMap::updateTile(int x, int y)
{
	for (int cury = y - 1; cury <= y + 1; cury++) {
		for (int curx = x - 1; curx <= x + 1; curx++) {
			// curx, cury ��ġ�� ���Ӹ��� ������ ��� ��� ==> nothing
			if (curx < 0 || curx > m_width - 1 || cury < 0 || cury > m_height - 1)
				continue;
			// (curx, cury) == (x, y) �ΰ�� ==> �̹� ���ڰ� ��ġ�� �Ǿ� ���� ==> nothing
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

	// ���� ������ ����ų� �̹� ������ Ÿ���� �״�� �д�.
	if (x < 0 || x > m_width - 1 || y < 0 || y > m_height - 1 || curTile.isTileOpened())
	{
		return -2;
	}

	// (x, y)�� ���ڰ� �ִ� ��� ==> ��� Ÿ���� ����
	if (curTile.getTileNum() == MINE) 
	{
		openAllTile();
		return -1;
	}

	// (x, y)Ÿ���� ���� �������� ���� Ÿ���̸�
	if (!curTile.isTileOpened()) 
	{
		curTile.setTileOpened(true);

		if (curTile.getTileNum() == ZERO)
		{
			for (int posX = -1; posX < 2; posX++) 
			{
				for (int posY = -1; posY < 2; posY++)
				{
					// �ڱ� �ڽ��� ��쿡�� continue ó�� �� �ִ� ���� ����!
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
