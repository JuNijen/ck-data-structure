#include "Plane.h"
#include "GameMap.h"
#include <conio.h>

void Plane::Update() 
{
	// (curX, curY) : current plane pos
	int curX = getX();
	int curY = getY();
	int nKey;

	if (_kbhit()) // if keyboard hit 
	{
		nKey = _getch();
		switch (nKey)
		{
		case LEFT: // move plane 1block left
			if (curX-1 > 0) 
			{
				m_x--;
			}
			break;
		case RIGHT: // move plane 1block right
			if (curX + 1 < GameMap::mapWidth -1)
			{
				m_x++;
			}
			break;
		case SPACE: // shoot boolet -> add on list -> gonna make later
			break;
		default:
			break;
		}
	}
}