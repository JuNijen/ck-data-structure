#include <iostream>
using namespace std;


// [과제] 자판기 프로그램을 구현합니다.
// 아래 내용을 만족하는 자판기 프로그램을 구현합니다.

// 1. 객체들 : 버튼, 모터, 자판기
// 2. 자판기 메뉴 : 차거운물 / 조각얼음 / 큐브얼음
// 3. 사용자는 자판기의 메뉴 버튼을 누릅니다.
// 4. 자판기는 해당되는 메뉴의 내용을 만들어서 내보냅니다.
// 추상화에 따른 구조체(클래스) 단위로 프로그램을 구현합니다.

// 주의사항 :
// 1. 제출기한 :  9월 9일까지
// 2. 제출기한을 엄수합니다.


//chilledWater  //차가운물
//crushedIce    //조각얼음
//cubeIce       //큐브얼음

//사용자는 원하는 메뉴 버튼을 눌러 선택합니다.
//자판기는 사용자가 누른 버튼을 결과물을 만들어서 제공합니다.



struct Motor
{
	void running(string *pMenuName);
};

void Motor::running(string *pMenuName)
{
	cout << pMenuName->data() << " 제조 진행 중" << endl;
}



struct Button
{
	string name;

	// Button(string *pName) : name(pName) {};
	void setName(string *pName);
	string getName();
	void pushedButton(Motor *pMotor);
	//Button makeButton(string *pName);
};

void Button::setName(string *pName)
{
	name = *pName;
}

string Button::getName() 
{
	return name;
}

void Button::pushedButton(Motor *pMotor)
{
	//cout << &name;
	pMotor->running(&name);
}

//Button Button::makeButton(string *pName) 
//{
//	Button button;
//	string buttonName;
//	button.setName(&buttonName);
//
//	return button;
//}



struct Machine
{
	// member variables
	Button buttons[3];
	// Motor *motor;
	int userNumber = -1;

	// member methods
	//Machine(Button[3] *pButton) : button(pButton) {};
	void setMachine();
	void pushButton();
	void draw();
	void printMenu();
};

void Machine::setMachine()
{
;	//userNumber = -1;


	Button button;
	string buttonName;

	buttonName = "차가운 물";
	button.setName(&buttonName);
	buttons[0] = button;

	buttonName = "조각 얼음";
	button.setName(&buttonName);
	buttons[1] = button;

	buttonName = "큐브 얼음";
	button.setName(&buttonName);
	buttons[2] = button;
}

void Machine::pushButton()
{
	cout << "주문할 번호를 입력 해 주세요. >> ";
	cin >> userNumber;

	Motor *motor = new Motor;

	buttons[userNumber].pushedButton(motor);
	cout << buttons[userNumber].name.data() << " 제작 진행" << endl;
}

void Machine::draw()
{
	cout << "제조 완료" << endl << endl;
}

void Machine::printMenu()
{
	for (int i = 0; i < 3; i++)
	{
		string name = buttons[i].name;

		cout << buttons[i].name.data() << " : " << i << endl;
	}
	cout << endl;
}



//int main()
//{
//	Machine *machine = new Machine;
//	machine->setMachine();
//	machine->printMenu();
//	machine->pushButton();
//	machine->draw();
//
//	return 0;
//}