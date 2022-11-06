#pragma once
#include "LarvaGameLinkedList.h"
#include "LarvaGameObject.h"
#include "LarvaGameSnake.h"
#include "LarvaGameMap.h"
#include "LarvaGameUtil.h"
#include <iostream>
using namespace std;


class LarvaGameManager
{
public:
	static bool m_bContinueStatus;

public:
	static bool GetStatus() ;
	static void SetStatus(bool status);

	LarvaGameManager() { GameInit(); };
	~LarvaGameManager() {};

	bool GameInit();
	bool Draw();
	bool Update();
	bool MakeItem();

private:
	//���� ũ��, ���ǵ带 �Է¹��� �� �ְԲ�.
	//ȭ�鵵 �׷��ָ� ������.
	
	GameMap*	m_gameMap;
	Snake*		m_snake;
	int				m_gameSpeed;
};

bool LarvaGameManager::m_bContinueStatus = true;