#include <iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

//2022년 09월 21일 강의
//Lecture 04. 기본 자료구조의 이해와 활용

// "지뢰찾기" 게임의 맵을 구성합니다.
// - 2차원 배열을 이용한다.
// - 지뢰 설치(7개) 위치는 랜덤하게 처리한다.
// - 지뢰의 값은 -1 또는 9로 설정한다.
// - 셀의 값은 셀 주변의 지뢰의 개수로 설정한다.

// 1. 필요한 객체를 추상화하여 클래스 단위로 구현합니다.
// 2. 맵은 2차원 배열의 형태로 구현합니다. 이 때 맵의 변수는 이중 포인터 변수를 선언하고 동적메모리로 할당합니다.
// 3. 지뢰 설치 위치는 랜덤하게 처리합니다.
// 4. 설치할 지뢰의 개수는 프로그래머가 정합니다.
// 5. 지뢰가 없는 셀은 주변 지뢰의 개수를 값으로 가집니다.
// 6. 셀도 하나의 객체이므로 가능하면 추상화하여 클래스로 구현합니다.

// #define MINE -1;
// #define MAP_MAX_X 8;
// #define MAP_MAX_Y 8;


class Map
{
    public:
    Map(int mineMaxCount)
    {
        m_mineMaxCount = mineMaxCount;
        memset(m_mineArray, 0, sizeof(m_mineArray)); // initalize mine data to 0
    };
    ~Map(){};

    void PrintData();   // print mine array data
    void InitMap();     // set non-mine area data

    private:
    const int MINE = -1;
    // const int MINE_MAX_COUNT = 7;
    const int MAP_MAX_X = 8;
    const int MAP_MAX_Y = 8;
	const int CHECK_MINE_ARRANGE = 2;

    int m_mineArray[8][8];
    int m_mineMaxCount;

    void InitBomb();    // set random mine data
    void SetBomb(int x, int y); // check is bomb
    int  SetArea(int x, int y); // check area count

};

void Map::PrintData()
{
    for (int x = 0; x < MAP_MAX_X; x++)
    {
		cout << endl;
		for (int y = 0; y < MAP_MAX_Y; y++)
        {
            switch(m_mineArray[x][y])
            {
                case -1: // MINE
	                printf("%2d", 9);
		            break;

                default:
					printf("%2d", m_mineArray[x][y]);
					//cout << m_mineArray[x][y];
			        break;
            }
        }
    }
}

void Map::InitMap()
{
    InitBomb();
	PrintData();
	cout << endl;

    for (int x = 0; x < MAP_MAX_X; x++)
    {
        for (int y = 0; y < MAP_MAX_Y; y++)
        {
            if(m_mineArray[x][y] != 9)
            {
                m_mineArray[x][y] = SetArea(x, y);
            }
        }
    }
}

// 지뢰 설치 위치는 랜덤하게 처리한다.
// - 지뢰의 값은 -1 또는 9로 설정한다.
// - 셀의 값은 셀 주변의 지뢰의 개수로 설정한다.
void Map::InitBomb()
{
    for (int count = 0; count < m_mineMaxCount; count++)
    {
        int randomX, randomY;

        // 초기 시드 값을 지정하고, 랜덤값을 부여한다
		srand((unsigned) time(NULL));
        randomX = std::rand() % MAP_MAX_X;
        randomY = std::rand() % MAP_MAX_Y;

        SetBomb(randomX, randomY);
    }
    cout << "Map::InitMap() >> 전체 폭탄 설정 완료" << endl;
}

// 지뢰를 설치한다.
void Map::SetBomb(int x, int y)
{
    // 폭탄이 없을 경우 설치
    if(m_mineArray[x][y] != 9)
    {
		printf("Map::SetBomb() >> (%d, %d) 폭탄 설정 완료.\n", x, y);
		m_mineArray[x][y] = 9;
    }
    // 폭탄이 있는 위치일 경우, 폭탄이 없는 곳에 설치 할 때 까지 반복.
    else
    {
        int randomX, randomY;

		//srand((unsigned)time(NULL));
		randomX = std::rand() % MAP_MAX_X;
        randomY = std::rand() % MAP_MAX_Y;

        SetBomb(randomX, randomY);
    }
}

int Map::SetArea(int x, int y)
{
    int countResult = 0;
	// 1. 0
	// 0. 1
	// 1. 1
    // if(x < 0 || x > 3)
    // {
        
    // }
	int currentX, currentY;

	for (int checkX = -1; checkX < CHECK_MINE_ARRANGE; checkX++)
	{
		currentX = x + checkX;


        // 좌측 또는 우측에 더 값이 없을 경우, 스킵 해 준다.
        if(currentX < 0 || currentX > MAP_MAX_X)
        {
            continue;
        }

		for (int checkY = -1; checkY < CHECK_MINE_ARRANGE; checkY++)
		{
            currentY = y + checkY;
 

            // 상단 또는 하단에 더 값이 없을 경우, 스킵 해준다.
            if(currentY < 0 || currentY > MAP_MAX_Y)
            {
                continue;
            }
            // 자기 자신은 체크 해 주지 않는다.
            else if(currentX == x && currentY == y)
            {
                continue;
            }
			else 
			{
				if (m_mineArray[currentX][currentY] == 9) 
				{
		            countResult++;
				}
			}
		}
	}

	return countResult;
}



int main(int argc, char* argv[])
{
	int customBombCount = 0;

	do 
	{
		cout << "플레이 할 폭탄의 개수를 설정합니다. 30 이내의 원하는 값을 입력 해 주세요.>> ";
		cin >> customBombCount;
	}
	while (!(customBombCount > 0 && customBombCount < 30));

    Map *gameMap = new Map(customBombCount);
    gameMap->InitMap();
    gameMap->PrintData();

    gameMap->~Map();

    return 0;
}