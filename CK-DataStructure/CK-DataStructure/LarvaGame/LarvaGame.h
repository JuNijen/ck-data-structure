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
	enum GAME_MENU
	{
		GAME_MENU_EASY,
		GAME_MENU_NORMAL,
		GAME_MENU_HARD,
		GAME_MENU_EXIT
	};

public:
	static bool m_bContinueStatus;

public:
	static bool GetStatus() ;
	static void SetStatus(bool status);

	LarvaGameManager() { GameInit(); };
	~LarvaGameManager() {};

	bool Draw();
	bool Update();
	bool MakeItem();
	void GameStartScreen();
	void KeyInput();
	void GameOverScreen();

private:
	//추후 크기, 스피드를 입력받을 수 있게끔.
	//화면도 그려주면 좋을듯.
	
	GameMap*	m_gameMap;
	Snake*		m_snake;
	int				m_gameSpeed;
	int				m_mapWidth;
	int				m_mapHeight;

	bool GameInit();
	void PrintGameMenu(int x, int y);
};

bool LarvaGameManager::m_bContinueStatus = true;