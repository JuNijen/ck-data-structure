#include "Mine/util.h"
#pragma once

class GameObject
{
protected:
	int m_x;
	int m_y;
	wchar_t* m_img; // object image

public:
	GameObject() : m_x(0), m_y(0), m_img((wchar_t*)L" ") {};
	GameObject(int x, int y, wchar_t* img) : m_x(x), m_y(y), m_img(img) {};
	~GameObject() {};

	// getters
	int getX() { return m_x; };
	int getY() { return m_y; };
	wchar_t* getImg() { return m_img; };

	// setters
	void setXY(int x, int y) { m_x = x; m_y = y; };
	void setImg(wchar_t* img) { m_img = img; };

	virtual bool collision(GameObject* other)
	{
		if (this->m_x == other->m_x && this->m_y == other->m_y)
		{
			return true;
		}
		return false;
	}

	virtual void Update() {};
	virtual void Draw() 
	{
		ScreenPrint(m_x, m_y, m_img);
	};
};