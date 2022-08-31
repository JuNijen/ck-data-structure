// https://discord.com/channels/420967090762022912/694413642644455464/1014354567296725094
// 문제 : 숫자 맞추기 게임을 프로그램으로 구현 하시오

// [분석]
// 1. 컴퓨터 : 랜덤 값을 생성하여 지정한다.
// 2. 플레이어 : 숫자를 입력한다.
// 3. 입력한 숫자를 지정한 값과 비교한다.
// 4. 입력한 숫자가 크면  "정답보다 크다"는 것을 알려주고 다시 입력 받는다.
// 5. 입력한 숫자가 작으면 "정답보다 작다"는 것을 알려주고 다시 입력 받는다.
// 6. 입력한 숫자가 지정한 값과 같으면 종료한다.
// 7. 입력한 숫자가 정답과 일치할 때 까지 2~6을 반복한다.
// # 맞출 수 있는 기회는 최대 10회로 한다.

// 프로그래밍 툴  : Visual Studio
// 프로그래밍 언어 : C++
// 객체지향  or 절차적 프로그래밍

#include <iostream>
#include <random>

int createRandomNumber() {
    // 시드값을 얻기 위한 random_device 생성.
    std::random_device random;
    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 generate(random());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> range(0, 99);

    return range(generate);
}


int main(int argc, char* argv[]) {

    int randomNumber = createRandomNumber();
    std::cout << randomNumber;
    int userNumber = -1;
    int count = 0;

    while(userNumber != randomNumber && count < 10) {
        std::cout << std::endl << std::endl << count+1 << "/10 회차 추측값을 입력하세요 : ";
        std::cin >> userNumber;
        count++;

        if(userNumber == randomNumber) {
            std::cout << "정답입니다.";
        }
        else if(userNumber > randomNumber) {
            std::cout << "정답보다 크다." << std::endl;
        }
        else {
            std::cout << "정답보다 작다." << std::endl;
        }
    }
  
    return 0;
}