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
	//추후 크기, 스피드를 입력받을 수 있게끔.
	//화면도 그려주면 좋을듯.
	
	GameMap*	m_gameMap;
	Snake*		m_snake;
	int				m_gameSpeed;
};

bool LarvaGameManager::m_bContinueStatus = true;