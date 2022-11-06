#include "LarvaGame.h"


int main() 
{
	LarvaGameManager *larvaGM = new LarvaGameManager();
	LarvaGameManager::SetStatus(larvaGM->GameInit());

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

	//추후 난이도 선택 가능하게끔
	m_mapWidth = 20;
	m_mapHeight = 20;
	m_gameSpeed = 200;

	m_gameMap = new GameMap(m_mapWidth, m_mapHeight);
	m_snake = new Snake(m_mapWidth /2, m_mapHeight /2, (wchar_t*)L"□", m_gameSpeed);

	ScreenInit();
	m_gameMap->InitMap();
	m_snake->SetMap(m_mapWidth, m_mapHeight);
	m_snake->MakeItem();
	bResult = true;

	return bResult;
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
	ScreenPrint(9, 15, (wchar_t*)L"SnakeGame!");
	_getch();
}

void LarvaGameManager::GameOverScreen()
{
	int gameoverX = 2;
	int gameoverY = 2;

	wchar_t* str[] =
	{
		(wchar_t*)L"　■■■　　　■■■　　■■　■■　■■■■■",
		(wchar_t*)L"■　　　　　■　　　■　■　■　■　■　　　　",
		(wchar_t*)L"■　■■■　■■■■■　■　■　■　■■■■■",
		(wchar_t*)L"■　　　■　■　　　■　■　■　■　■　　　　",
		(wchar_t*)L"　■■■　　■　　　■　■　　　■　■■■■■",
		(wchar_t*)L"　　　　　　　　　　　　　　　　　　　　　　　",
		(wchar_t*)L"　■■■　　■　　　■　■■■■■　■■■■　",
		(wchar_t*)L"■　　　■　■　　　■　■　　　　　■　　　■",
		(wchar_t*)L"■　　　■　■　　　■　■■■■■　■■■■　",
		(wchar_t*)L"■　　　■　　■　■　　■　　　　　■　　　■",
		(wchar_t*)L"　■■■　　　　■　　　■■■■■　■　　　■",
	};

	// 　■■■　　　■■■　　■■　■■　■■■■■
	// ■　　　　　■　　　■　■　■　■　■　　　　
	// ■　■■■　■■■■■　■　■　■　■■■■■
	// ■　　　■　■　　　■　■　■　■　■　　　
	// 　■■■　　■　　　■　■　　　■　■■■■■
	//
	// 　■■■　　■　　　■　■■■■■　■■■■　
	// ■　　　■　■　　　■　■　　　　　■　　　■
	// ■　　　■　■　　　■　■■■■■　■■■■　
	// ■　　　■　　■　■　　■　　　　　■　　　■
	// 　■■■　　　　■　　　■■■■■　■　　　■

	ScreenClear();
	SetColor(4);

	for (int i = 0; i < 11; i++) ScreenPrint(gameoverX, gameoverY + i, str[i]);

	SetColor(2);
	ScreenPrint(9, 15, (wchar_t*)L"Press key to exit");
	ScreenFlipping();
	_getch();
}
