#pragma once
#include "LarvaGameLinkedList.h"
#include "LarvaGameObject.h"
#include "LarvaGameMap.h"
#include <windows.h>
#include <conio.h>


class Snake : public GameObject
{
private:
	int m_mapWidth;
	int m_mapHeight;
	int m_speed;
	bool m_status;
	CLinkedList* m_snakeBody;
	GameObject m_item;

public:
	Snake(int x, int y, wchar_t* img, int speed = 100) : GameObject(x, y, img), m_speed(speed)
	{ 
		m_status = true; 
		m_snakeBody = new CLinkedList();
		m_snakeBody->insert(1, new GameObject(x, y, img));
	};
	Snake() { };
	~Snake() {};

	void Update() override;
	void Draw() override;

	void SetSpeed(int speed) { m_speed = speed; };
	void SetMap(int width, int height) { m_mapWidth = width, m_mapHeight = height; };
	void MakeItem();
	bool GainItem();
	bool IsAlive() { return m_status; };
};