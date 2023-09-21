#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "thu_vien.h"
using namespace std;

typedef long long ll;


int main()
{
    FixConsoleWindow();
    cout << "Hello World :0000011111";
    while (true)
    {
        if (_kbhit())
        {
            COORD currentCoord = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)); // get current (x,y)
            switch (_getch())
            {
            case 'a':
                cout << 'a';
                GotoXY(currentCoord.X - 1, currentCoord.Y);
                break;
            case 'w':
                cout << 'w';
                GotoXY(currentCoord.X, currentCoord.Y - 1);
                break;
            case 's':
                cout << 's';
                GotoXY(currentCoord.X, currentCoord.Y + 1);
                break;
            case 'd':
                cout << 'd';
                GotoXY(currentCoord.X + 1, currentCoord.Y);
                break;
            default:
                break;
            };
        }
    }
    return 0;
}
