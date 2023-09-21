#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

typedef long long ll;

void FixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);


    // Define the custom height and width
    int customWidth = 80;  // Replace with your desired width
    int customHeight = 40; // Replace with your desired height
    // Get the handle to the console window
    //HWND consoleWindow = GetConsoleWindow();
    // Create a SMALL_RECT structure to define the new console size
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = customWidth - 1;
    rect.Bottom = customHeight - 1;
    // Set the console screen buffer size to match the new size
    COORD size;
    size.X = customWidth;
    size.Y = customHeight;
    // Set the console window size and screen buffer size
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);



    // get handle to the console window
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // retrieve screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
    // current window size
    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;
    // current screen buffer size
    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;
    // to remove the scrollbar, make sure the window height matches the screen buffer height
    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;
    // set the new screen buffer dimensions
    int Status = SetConsoleScreenBufferSize(hOut, newSize);
    if (Status == 0)
    {
        cout << "SetConsoleScreenBufferSize() failed! Reason : " << GetLastError() << endl;
        exit(Status);
    }


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

int main()
{
    FixConsoleWindow();
    cout << "   _________    ____  ____\n";
    cout << "  / ____/   |  / __ \\/ __ \\ \n";
    cout << " / /   / /| | / /_/ / / / / \n";
    cout << "/ /___/ ___ |/ _, _/ /_/ / \n";
    cout << "\\____/_/  |_/_/ |_|\\____/  \n";
    /*
   _________    ____  ____ 
  / ____/   |  / __ \/ __ \
 / /   / /| | / /_/ / / / /
/ /___/ ___ |/ _, _/ /_/ / 
\____/_/  |_/_/ |_|\____/  

    */


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
