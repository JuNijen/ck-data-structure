#include "GameObject.h"
#include "GameMap.h"
#include "Mine/util.h"
#include "Plane.h"

int GameMap::mapWidth = 50;
int GameMap::mapHeight = 30;

int main() 
{
	GameMap* gameMap = new GameMap();
	GameObject* plane = new Plane(GameMap::mapHeight/2, GameMap::mapHeight-2, (wchar_t*)L"бу");

	ScreenInit();
	bool bContinue = true;

	while (bContinue) 
	{
		ScreenClear(GameMap::mapWidth, GameMap::mapHeight);
		gameMap->Draw();
		plane->Draw();
		ScreenFlipping();

		plane->Update();
	}

	return 0;
}