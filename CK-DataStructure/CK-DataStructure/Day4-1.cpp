#include <iostream>
using namespace std;

void swapV(int a, int b)
{
    int temp = a;
    a = b;
    b = a;

    cout << " a : " << a << " b : " << b << endl;
}

void swapA(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = a;

    cout << " a : " << a << " b : " << b << endl;
}

void swapR(int &a, int &b)
{
    int temp = a;
    a = b;
    b = a;

    cout << " a : " << a << " b : " << b << endl;
}


int main () 
{
    int a = 23;
    int b = 17;

    cout << "call by value >> ";
    swapV(a, b);

    cout << "call by address >> ";
    swapA(&a, &b);

    cout << "call by reference >> ";
    swapR(a, b);

    return 0;
}
