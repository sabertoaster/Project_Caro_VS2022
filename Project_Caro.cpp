#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "thu_vien.h"
using namespace std;

typedef long long ll;


void draw()
{
    int n = 500;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << '-';
        }
        cout << '\n';
    }
}
int main()
{
    resizeConsole(500, 500);
    FixConsoleWindow();
    cout << "hello world";
    while (true)
    {
        move();
    }
    return 0;
}
