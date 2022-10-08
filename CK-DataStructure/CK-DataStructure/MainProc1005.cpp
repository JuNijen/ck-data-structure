#include <conio.h>
#include <thread>
#include "util.h"
#include "GameMap.h"
#include "GameCursor.h"

using namespace std;


void TestProc();

int main() 
{
	bool bContinue = true;
	int openTileNum = 0;

	GameMap gameMap(20, 20);
	gameMap.setMine(20);

	GameCursor cursor(5, 5);

	//Game Loop
	ScreenInit();

	while (bContinue)
	{
		// Draw Call
		ScreenClear();
		gameMap.draw();
		cursor.draw();
		ScreenFlipping();

		// Keyboard Input
		int nKey;
		int cursorX;
		int cursorY;

		if (_kbhit()) 
		{
			nKey = _getch();
			cursorX = cursor.GetX();
			cursorY = cursor.GetY();

			switch (nKey)
			{
			case UP:
				if (cursorY - 1 >= 0)
				{
					cursor.MoveUp();
				}
				break;
			case DOWN:
				if (cursorY + 1 <= gameMap.getHeight() - 1)
				{
					cursor.MoveDown();
				}
				break;
			case LEFT:
				if (cursorX - 1 >= 0)
				{
					cursor.MoveLeft();
				}
				break;
			case RIGHT:
				if (cursorX + 1 <= gameMap.getWidth() - 1)
				{
					cursor.MoveRight();
				}
				break;
			case SPACE:
				openTileNum = gameMap.openTile(cursorX, cursorY);
				if (openTileNum == -1)
				{
					bContinue = false;
				}
				break;
			default:
				break;
			}
		}
	}

	return 0;
}



void TestProc()
{
	ScreenInit();

	bool bContinue = true;
	while (bContinue)
	{
		this_thread::sleep_for(200ms);
		ScreenClear();

		SetColor(rand() % 15);
		ScreenPrint(rand() % 80, rand() % 25, L"HELLO");
		ScreenPrint(rand() % 80, rand() % 25, L"Everybody");
		ScreenPrint(rand() % 80, rand() % 25, L"am Sieun");

		ScreenFlipping(); //없으면 아무것도 보이지 않음.

		int nKey = 0;
		if (_kbhit()) //  키보드가 눌렸는가
		{
			nKey = _getch();

			switch (nKey)
			{
			case SPACE:
				bContinue = false;
				break;
			default:
				break;
			}
		}
	}
}