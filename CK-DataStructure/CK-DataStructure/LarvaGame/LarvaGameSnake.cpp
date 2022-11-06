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
		int i = 0;
		switch (curVector)
		{
		case LEFT:
			if (m_x - 1 > 0) 
			{
				m_x--;
				while (m_snakeBody->retrieve(i) != nullptr)
				{
					m_snakeBody->retrieve(i)->setXY(m_x-(1 * i) - 1, m_y);
					i++;
				}
			}
			else m_status = false;
			break;
		case RIGHT:
			if (m_x + 1 < m_mapWidth - 1) 
			{
				m_x++;
				while (m_snakeBody->retrieve(i) != nullptr)
				{
					m_snakeBody->retrieve(i)->setXY(m_x + (1 * i) + 1, m_y);
					i++;
				}
			}
			else m_status = false;
			break;
		case UP:
			if (m_y - 1 > 0) 
			{
				m_y--;
				while (m_snakeBody->retrieve(i) != nullptr)
				{
					m_snakeBody->retrieve(i)->setXY(m_x, m_y - (1 * i) - 1);
					i++;
				}
			}
			else m_status = false;
			break;
		case DOWN:
			if (m_y + 1 < m_mapHeight - 1) 
			{
				m_y++;
				while (m_snakeBody->retrieve(i) != nullptr)
				{
					m_snakeBody->retrieve(i)->setXY(m_x, m_y+ (1 * i) + 1);
					i++;
				}
			}
			else m_status = false;
			break;
		default:
			break;
		}
	}
	GainItem();
	Sleep(m_speed);
}

void Snake::Draw()
{
	ScreenPrint(m_x, m_y, m_img);
	ScreenPrint(m_item.getX(), m_item.getY(), m_item.getImg());

	int i = 0;
	while(m_snakeBody->retrieve(i) != nullptr)
	{
		m_snakeBody->retrieve(i)->Draw();
		i++;
	}
}

void Snake::MakeItem() 
{
	int randX = (rand() % (m_mapWidth - 2)) + 1;
	int randY = (rand() % (m_mapHeight - 2)) + 1;

	int i = 0;
	while (m_snakeBody->retrieve(i) != nullptr)
	{
		if (m_snakeBody->retrieve(i)->getX() == randX || m_snakeBody->retrieve(i)->getY() == randY) // item can't be on snake's body
		{
			randX = (rand() % (m_mapWidth - 2)) + 1;
			randY = (rand() % (m_mapHeight - 2)) + 1;
		}
		i++;
	}
	m_item = * new GameObject(randX, randY, (wchar_t*)L"O");
}

bool Snake::GainItem()
{
	bool bResult = false;
	if (m_x == m_item.getX() && m_y == m_item.getY()) // if snake's head on same position
	{
		MakeItem(); // make new one
		m_snakeBody->append(new GameObject(m_x, m_y, (wchar_t *)L"бр"));
	}

	return bResult;
}
