#include "util.h"

#include <Windows.h>
#include <assert.h>
#include <wincon.h>

#pragma warning(disable:4996)

// ��� ���
// util ���̺귯�� �Լ��� ����Ϸ��� #include "util.h" �� �����մϴ�.
// ScreenInit() �Լ��� ���� gameloop ���� ���� �ʱ�ȭ�մϴ�.
// ScreenClear() �Լ��� ���� ȭ���� ����ϴ�.
// ScreenPrint()�Լ��� (x, y) ��ġ�� ���ڿ��� �ۼ��մϴ�.
// ScreenFlipping() �Լ��� ȣ���Ͽ� ȭ���� ������Ʈ �մϴ�.
// Gameloop�� ����Ǹ� ScreenRelease()�Լ��� ȭ�� ���۸� �����մϴ�.


static int g_nScreenIndex;
static HANDLE g_hScreen[2];


wchar_t* CharToWChar(const char* pstrSrc)
{
    assert(pstrSrc);
    int nLen = strlen(pstrSrc) + 1;

    wchar_t* pwstr = (LPWSTR)malloc(sizeof(wchar_t) * nLen);
    mbstowcs(pwstr, pstrSrc, nLen);

    return pwstr;
}


//wchar_t ���� char ���� ����ȯ �Լ�
char* ConvertWCtoC(const wchar_t* str)
{
    //��ȯ�� char* ���� ����
    char* pStr;

    //�Է¹��� wchar_t ������ ���̸� ����
    int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
    //char* �޸� �Ҵ�
    pStr = new char[strSize];

    //�� ��ȯ 
    WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);
    return pStr;
}



void gotoxy(int x, int y)
{
    SHORT tx = static_cast<SHORT>(x);
    SHORT ty = static_cast<SHORT>(y);
    COORD CursorPosition = { tx, ty };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}


 // ȭ�� �ʱ�ȭ - ȭ�� ���� 2�� ����
void ScreenInit()
{
     CONSOLE_CURSOR_INFO cci;
        
     // ȭ�� ���� 2���� �����.
     g_hScreen[0] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, 0,
                                            NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
     g_hScreen[1] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, 0,
                                            NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
 
     // Ŀ�� �����
     cci.dwSize = 1;
     cci.bVisible = FALSE;
     SetConsoleCursorInfo( g_hScreen[0], &cci );
     SetConsoleCursorInfo( g_hScreen[1], &cci );

}
 
// Black transfer?
// ȭ�� ��ü - ����� ������ ȭ�鿡 �ѷ���.
void ScreenFlipping()
{               
     SetConsoleActiveScreenBuffer( g_hScreen[g_nScreenIndex] );    
     g_nScreenIndex = !g_nScreenIndex; 
}
 
// ȭ�� Ŭ����, ������ �����ŭ blank�� �׷���.
void ScreenClear(int width, int height)
{               
     COORD Coord = { 0, 0 };
     DWORD dw;
     width *= 2;
     height *= 2;
     FillConsoleOutputCharacterW(g_hScreen[g_nScreenIndex], L' ', width * height, Coord, &dw);
//     FillConsoleOutputCharacter( g_hScreen[g_nScreenIndex], ' ', 80*25, Coord, &dw );
}
 
// ���� �޸� ����
void ScreenRelease()
{
     CloseHandle( g_hScreen[0] );
     CloseHandle( g_hScreen[1] );
}
 
// ����ۿ� �ؽ�Ʈ�� �׷���.
//void ScreenPrint(int x, int y, const char* string)
void ScreenPrint( int x, int y, const wchar_t *string )
{
     DWORD dw;
     SHORT tx = static_cast<SHORT>(x);
     SHORT ty = static_cast<SHORT>(y);
     COORD CursorPosition = { tx*2, ty };
    
     //DWORD dw2;
     //if (!WriteConsoleOutputCharacterW(g_hScreen[g_nScreenIndex], string, wcslen(string), CursorPosition, &dw))
     //{
     //    dw2 = GetLastError();
     //}
     SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition); // Ŀ�� ��ġ�� �̵������ش�.

	 char* str = ConvertWCtoC(string);
     WriteFile(g_hScreen[g_nScreenIndex], str, strlen(str), &dw, NULL); //���ڸ� ��� �� �ش�.
 //     WriteFile(g_hScreen[g_nScreenIndex], string, wcslen(string), &dw, NULL);
     

//     SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
//     WriteFile( g_hScreen[g_nScreenIndex], string, wcslen( string ), &dw, NULL );
}

// ���� ���ۿ� �÷��� �Ķ���� color�� �־��� �÷��� �ٲ���.
// 0 ~ 15 ���� ���� ���� ����
void SetColor( unsigned short color )
{
    SetConsoleTextAttribute( g_hScreen[g_nScreenIndex], color );
}