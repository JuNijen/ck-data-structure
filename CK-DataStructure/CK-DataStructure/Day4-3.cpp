#include <iostream>
#include <random>
using namespace std;


int main ()
{
    const int Row = 3;
    const int Col = 5;
    int ** arr = new int *[Row];
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);

    for (int i = 0; i < 3; i++) {
        arr[i] = new int[Col];

        for(int j = 0; j < 5; j++){
            arr[i][j] = dis(gen);
            cout << arr[i][j] << endl;
        }
    }

    return 0;
}
