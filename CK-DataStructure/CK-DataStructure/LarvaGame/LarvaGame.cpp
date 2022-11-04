#include "LarvaGame.h"


int main() 
{
	int mapSize = 20;
	int gameSpeed = 50;
	//GameMap* gameMap = new GameMap();
	GameMap* gameMap = new GameMap(mapSize, mapSize);
	CLinkedList* bulletList = new CLinkedList;
	Snake* snake = new Snake(
		//GameMap::mapWidth / 2,
		//GameMap::mapHeight / 2,
		gameMap->GetWidth() / 2, 
		gameMap->GetHeight() / 2, 
		(wchar_t*)L"бр",
		gameSpeed
	);

	ScreenInit();
	gameMap->InitMap();
	gameMap->SetItem(GameObject(rand()% gameMap->GetWidth(), rand()% gameMap->GetHeight(), (wchar_t*)L"O"));
	snake->SetMap(
		gameMap->GetWidth(), gameMap->GetHeight()
		//GameMap::mapWidth, GameMap::mapHeight
	);

	while (LarvaGame::bContinue) {
		//ScreenClear(GameMap::mapWidth, GameMap::mapHeight);
		ScreenClear();
		gameMap->Draw();
		snake->Draw();
		snake->Update();
		ScreenFlipping();
	}

	return 0;
}