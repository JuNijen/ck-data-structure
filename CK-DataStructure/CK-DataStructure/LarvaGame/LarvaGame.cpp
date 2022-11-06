#include "LarvaGame.h"


int main() 
{
	LarvaGameManager *larvaGM = new LarvaGameManager();
	LarvaGameManager::SetStatus(larvaGM->GameInit());
	//larvaGM->SetState(larvaGM->GameInit());

	while (LarvaGameManager::GetStatus())
	{
		larvaGM->Draw();
		larvaGM->Update();
	}

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

	//추후 선택 가능하게끔
	int mapWidth = 20;
	int mapHeight = 20;
	m_gameSpeed = 200;

	m_gameMap = new GameMap(mapWidth, mapHeight);
	m_snake = new Snake( mapWidth/2, mapHeight/2, (wchar_t*)L"□", m_gameSpeed);

	ScreenInit();
	m_gameMap->InitMap();
	m_snake->SetMap(mapWidth, mapHeight	);
	m_snake->MakeItem();
	bResult = true;

	return bResult;
}

bool LarvaGameManager::Draw()
{
	bool bResult = false;

	//ScreenClear(GameMap::mapWidth, GameMap::mapHeight);
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
	//SetStatus(m_snake->IsAlive());
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
