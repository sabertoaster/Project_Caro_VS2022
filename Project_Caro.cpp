#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "thu_vien.h"
using namespace std;

typedef long long ll;


int main()
{
    resizeConsole(500, 5000);
    FixConsoleWindow();
    cout << "hello world :)))";
    while (true)
    {
        move();
    }
    return 0;
}
