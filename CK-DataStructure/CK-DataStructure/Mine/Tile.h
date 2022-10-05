#pragma once

enum TileNumType { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, MINE };

class Tile
{
	int m_x;
	int m_y;
	int m_num;
	bool m_bOpened;
public:
	Tile() {}
	Tile(int x, int y) : m_x(x), m_y(y), m_num(ZERO), m_bOpened(true) {}

	// init
	void initTile(int x, int y);

	// getters
	int getX() { return m_x; }
	int getY() { return m_y; }
	int getTileNum() { return m_num; }
	bool isTileOpened() { return m_bOpened; }

	// setters
	void setXY(int x, int y) { m_x = x; m_y = y; }
	void setTileNum(int num) { m_num = num; }
	void setTileOpened(bool bOpen) { m_bOpened = bOpen; }
	void draw();
};
