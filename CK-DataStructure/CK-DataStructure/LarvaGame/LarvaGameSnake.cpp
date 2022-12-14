#include "LarvaGameSnake.h"

void Snake::Update()
{
	static int curVector = RIGHT;
	int nKey;

	if (_kbhit()) 
	{
		nKey = _getch();

		switch (nKey)
		{
		case LEFT:
			if (curVector != RIGHT) { curVector = LEFT; }
			break;
		case RIGHT:
			if (curVector != LEFT) { curVector = RIGHT; }
			break;
		case UP:
			if (curVector != DOWN) { curVector = UP; }
			break;
		case DOWN:
			if (curVector != UP) { curVector = DOWN; }
			break;

		default:
			break;
		}
	}
	else
	{
		Sleep(m_delay);
		switch (curVector)
		{
		case LEFT:
			if (m_x - 1 > 0) m_x--;
			else 
			{
			}
			break;
		case RIGHT:
			if (m_x + 1 < m_mapWidth - 1) m_x++;
			break;
		case UP:
			if (m_y - 1 > 0) m_y--;
			break;
		case DOWN:
			if (m_y + 1 < m_mapHeight - 1) m_y++;
			break;
		default:
			break;
		}
	}
}

void Snake::Draw()
{
	ScreenPrint(m_x, m_y, m_img);
}

//			bullet = new Bullet(m_x, m_y, (wchar_t *)L"??");
//			GameManager::getInstance()->getBulletList()->append(new Bullet(m_x, m_y, (wchar_t*)L"??"));
