#pragma once

class GameCursor 
{
	int m_x;
	int m_y;

public:
	GameCursor(int x = 0, int y = 0) : m_x(x), m_y(y){};
	~GameCursor() {};

	//getters
	int GetX() { return m_x; }
	int GetY() { return m_y; }

	// setters
	void SetXY(int x, int y) { m_x = x; m_y = y; };

	// cursor move
	void MoveUp() { m_y--;  }
	void MoveDown() { m_y++; }
	void MoveLeft() { m_x--; }
	void MoveRight() { m_x++; }

	void draw();
};