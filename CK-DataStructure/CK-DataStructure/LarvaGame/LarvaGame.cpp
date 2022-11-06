#include "LarvaGame.h"


int main() 
{
	LarvaGameManager *larvaGM = new LarvaGameManager();
	larvaGM->GameStartScreen();

	while (LarvaGameManager::GetStatus())
	{
		larvaGM->Draw();
		larvaGM->Update();
	}

	larvaGM->GameOverScreen();
	return 0;
}


bool LarvaGameManager::GetStatus()
{
	return LarvaGameManager::m_bContinueStatus;
}

void LarvaGameManager::SetStatus(bool status)
{
	LarvaGameManager::m_bContinueStatus = status;
}

bool LarvaGameManager::GameInit()
{
	bool bResult = false;
	// easy = 200, normal = 100, hard = 50

	m_gameMap = new GameMap(m_mapWidth, m_mapHeight);
	m_snake = new Snake(m_mapWidth /2, m_mapHeight /2, (wchar_t*)L"¡à", m_gameSpeed);

	ScreenInit();
	m_gameMap->InitMap();
	m_snake->SetMap(m_mapWidth, m_mapHeight);
	m_snake->MakeItem();
	bResult = true;

	return bResult;
}

void LarvaGameManager::PrintGameMenu(int x, int y)
{
	wchar_t* menuText[] =
	{
		(wchar_t*)L"Easy mode",
		(wchar_t*)L"Normal mode",
		(wchar_t*)L"Hard mode",
		(wchar_t*)L"Exit",
	};

	ScreenPrint(3, 3, (wchar_t*)L"SnakeGame!");
	for (int i = 0; i < 4; i++) ScreenPrint(x, y + i, menuText[i]);
}

bool LarvaGameManager::Draw()
{
	bool bResult = false;

	//ScreenClear(m_mapWidth-1, m_mapHeight-1);
	ScreenClear();
	m_gameMap->Draw();
	m_snake->Draw();
	bResult = true;

	return bResult;
}

bool LarvaGameManager::Update()
{
	bool bResult = false;

	m_snake->Update();
	SetStatus(m_snake->IsAlive());
	ScreenFlipping();
	bResult = true;

	return bResult;
}

bool LarvaGameManager::MakeItem()
{
	bool bResult = false;

	m_snake->MakeItem();
	bResult = true;

	return bResult;
}

void LarvaGameManager::GameStartScreen()
{
	int menu = GAME_MENU_NORMAL;
	int menuX = 3;
	int menuY = 6;
	bool menuSelected = false;

	PrintGameMenu(menuX, menuY);
	ScreenPrint(2, menuY + menu, (wchar_t*)L"¢º");
	ScreenFlipping();

	while (!menuSelected)
	{
		int nKey = _getch();

		switch (nKey)
		{
		case UP:
			if (menu > GAME_MENU_EASY) { menu--; }
			break;
		case DOWN:
			if (menu < GAME_MENU_EXIT) { menu++; }
			break;
		case ENTER:
			menuSelected = true;
			break;
		}
		ScreenClear();
		ScreenPrint(2, menuY+menu, (wchar_t*)L"¢º");
		PrintGameMenu(menuX, menuY);
		ScreenFlipping();
	}

	switch (menu)
	{
	case GAME_MENU_EASY:
		m_mapWidth = 30;
		m_mapHeight = 30;
		m_gameSpeed = 200;
		break;

	case GAME_MENU_NORMAL:
		m_mapWidth = 20;
		m_mapHeight = 20;
		m_gameSpeed = 100;
		break;

	case GAME_MENU_HARD:
		m_mapWidth = 20;
		m_mapHeight = 20;
		m_gameSpeed = 50;
		break;

	case GAME_MENU_EXIT:
		//GameOverScreen();
		ScreenPrint(9, 15, (wchar_t*)L"Press key to exit");
		ScreenFlipping();
		_getch();
		exit(0);
		break;
	}
	LarvaGameManager::SetStatus(GameInit());
}

void LarvaGameManager::KeyInput()
{
	
}

void LarvaGameManager::GameOverScreen()
{
	int gameoverX = 2;
	int gameoverY = 2;

	wchar_t* gameOverText[] =
	{
		(wchar_t*)L"¡¡¡á¡á¡á¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡á¡¡¡á¡á¡¡¡á¡á¡á¡á¡á",
		(wchar_t*)L"¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡",
		(wchar_t*)L"¡á¡¡¡á¡á¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡á¡á¡á¡á",
		(wchar_t*)L"¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡",
		(wchar_t*)L"¡¡¡á¡á¡á¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡á",
		(wchar_t*)L"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡",
		(wchar_t*)L"¡¡¡á¡á¡á¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡¡",
		(wchar_t*)L"¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á",
		(wchar_t*)L"¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡¡",
		(wchar_t*)L"¡á¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á",
		(wchar_t*)L"¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡á¡á¡á¡á¡¡¡á¡¡¡¡¡¡¡á",
	};

	// ¡¡¡á¡á¡á¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡á¡¡¡á¡á¡¡¡á¡á¡á¡á¡á
	// ¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡
	// ¡á¡¡¡á¡á¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡á¡á¡á¡á
	// ¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡¡¡¡
	// ¡¡¡á¡á¡á¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡á
	//
	// ¡¡¡á¡á¡á¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡¡
	// ¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á
	// ¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡¡
	// ¡á¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á
	// ¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡á¡á¡á¡á¡¡¡á¡¡¡¡¡¡¡á

	ScreenClear();
	SetColor(4);

	for (int i = 0; i < 11; i++) ScreenPrint(gameoverX, gameoverY + i, gameOverText[i]);

	SetColor(2);
	ScreenPrint(9, 15, (wchar_t*)L"Press key to exit");
	ScreenFlipping();
	_getch();
}
