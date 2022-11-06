#include "LarvaGameSnake.h"


void Snake::Update()
{
	// if keyboard hit
	if (_kbhit()) KeyInput();
	else MoveSnake();

	GainItem();
	Sleep(m_speed);
}

void Snake::KeyInput()
{
	int nKey = _getch();

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

void Snake::MoveSnake()
{
	GameObject *head = m_snakeBody->retrieve(0);
	int x = head->getX();
	int y = head->getY();

	switch (curVector)
	{
	case LEFT:
		if (x - 1 > 0) x--;
		else m_status = false;
		break;
	case RIGHT:
		if (x + 1 < m_mapWidth - 1) x++;
		else m_status = false;
		break;
	case UP:
		if (y - 1 > 0) y--;
		else m_status = false;
		break;
	case DOWN:
		if (y + 1 < m_mapHeight - 1) y++;
		else m_status = false;
		break;
	default:
		break;
	}

	GameObject *moving = new GameObject(x, y, (wchar_t*)L"¢Ì");
	m_snakeBody->insert(0, moving);
	m_snakeBody->remove(m_snakeBody->length()-1);
	CheckStatus();
}

void Snake::Draw()
{
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

	m_item = * new GameObject(randX, randY, (wchar_t*)L"¢Ã");
}

bool Snake::GainItem()
{
	bool bResult = false;
	GameObject *head = m_snakeBody->retrieve(0);

	if (head->getX() == m_item.getX() && head->getY() == m_item.getY()) // if snake's head on same position
	{
		MakeItem(); // make new one
		m_snakeBody->append(new GameObject(head->getX(), head->getY(), (wchar_t *)L"¡à"));
	}

	return bResult;
}

void Snake::CheckStatus() 
{
	GameObject *head = m_snakeBody->retrieve(0);
	GameObject *current;

	int i = 1;
	while (m_snakeBody->retrieve(i) != nullptr)
	{
		current = m_snakeBody->retrieve(i);

		if (current->collision(head))
		{
			m_status = false;
		}
		i++;
	}
}