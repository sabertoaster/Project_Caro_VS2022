#pragma once
#include<stdio.h>
#include <windows.h>
void FixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// View
void GotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput) //return current pointer coordinate in console windows
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}
// View
void move()
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