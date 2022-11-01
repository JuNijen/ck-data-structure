#include "Tile.h"
#include "util.h"
#include <iostream>

using namespace std;

void Tile::initTile(int x, int y) 
{
	m_x = x;
	m_y = y;
	m_num = ZERO;
	m_bOpened = false;
}

void Tile::draw() 
{
	const wchar_t* tileImg[] = { L"��",L"��",L"��",L"��",L"��",L"��",L"��",L"��",L"��",L"��",L"��" };

	if (m_bOpened) 
	{
		ScreenPrint(m_x, m_y, tileImg[m_num]);
	}
	else 
	{
		ScreenPrint(m_x, m_y, tileImg[10]);
	}
}