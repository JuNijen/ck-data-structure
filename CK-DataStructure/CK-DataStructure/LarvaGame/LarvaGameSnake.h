#pragma once
#include "LarvaGameLinkedList.h"
#include "LarvaGameObject.h"
#include "LarvaGameMap.h"
#include <windows.h>
#include <conio.h>


class Snake : public GameObject
{
private:
	int curVector;
	int m_mapWidth;
	int m_mapHeight;
	int m_speed;
	bool m_status;
	CLinkedList* m_snakeBody;
	GameObject m_item;

	void KeyInput();
	void MoveSnake();

public:
	Snake(int x, int y, wchar_t* img, int speed = 100) : GameObject(x, y, img), m_speed(speed)
	{ 
		curVector = RIGHT;
		m_status = true; 
		m_snakeBody = new CLinkedList();
		m_snakeBody->insert(0, new GameObject(x, y, img));
	};
	Snake() { };
	~Snake() {};

	void Update() override;
	void Draw() override;

	void SetSpeed(int speed) { m_speed = speed; };
	void SetMap(int width, int height) { m_mapWidth = width, m_mapHeight = height; };
	void MakeItem();
	bool GainItem();
	void CheckStatus();
	bool IsAlive() { return m_status; };
};