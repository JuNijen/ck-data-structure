#include "GameCursor.h"
#include "util.h"

void GameCursor::draw() 
{
	const wchar_t* cursorImg = L"��";
	SetColor(10);
	ScreenPrint(m_x, m_y, cursorImg);
	SetColor(15);
}