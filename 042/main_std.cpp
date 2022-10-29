#include <iostream>
#include <unistd.h>

#include "2048.cpp"

unsigned int ms = 0.2 * 1000000;
using namespace std;

int main()
{
    int arr[4][4];
    int dir;

    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    cin >> dir;

    std::cout << "+--------+" << std::endl;
    std::cout << "| BEFORE |" << std::endl;
    std::cout << "| dir: " << dir << " |" << std::endl;
    std::cout << "+--------+" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i][0] << "\t" << arr[i][1] << "\t" << arr[i][2] << "\t" << arr[i][3] << endl;
    }

    run2048(arr, dir);

    std::cout << "+--------+" << std::endl;
    std::cout << "| AFTER  |" << std::endl;
    std::cout << "+--------+" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i][0] << "\t" << arr[i][1] << "\t" << arr[i][2] << "\t" << arr[i][3] << endl;
        usleep(ms);
    }

    std::cout << std::endl;
}
