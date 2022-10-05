#pragma once
#include "Tile.h"

class GameMap
{
	Tile** m_map;
	int m_width;
	int m_height;
	int m_mineNum;		// 설치할 지뢰의 갯수
	int m_openTileNum;	// 오픈한 타일의 갯수
public:
	GameMap(int w, int h) : m_width(w), m_height(h), m_openTileNum(0), m_mineNum(0) {
		m_map = new Tile *[h];
		for (int i = 0; i < h; i++)
			m_map[i] = new Tile[w];
		// tile들을 초기화
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				m_map[y][x].initTile(x, y);
			}
		}
	}
	~GameMap() {}

	//getters
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	int getMineNum() { return m_mineNum; }
	int getTileNum(int x, int y) { return m_map[y][x].getTileNum(); }

	// 지뢰설치
	void setMine(int mineNum);
	// 지뢰주변 타일의 num을 update (x, y)==> 지뢰 타일 위치
	void updateTile(int x, int y);

	// Tile open function
	int openTile(int x, int y); // open (x,y) pos tile
	void openAllTile(); // open all tile

	void draw();
};
