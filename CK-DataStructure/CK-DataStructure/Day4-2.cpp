#include <iostream>
using namespace std;


int main () 
{
    int y[12];
    int x[3][4] = {{3,2,4,8}, {6,5,7,9}, {10,32,12,43}};
    int count = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            y[count++] = x[i][j];
            cout << count-1 << " = " << y[count-1] << endl;
        }
    }

    return 0;
}
