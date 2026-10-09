#include "pch.h"
#include <iostream>
#include <time.h>

using namespace System;
using namespace std;

const int cols = 200;
const int rows = 45;

void initialSettings() {
    Console::SetWindowSize(cols, rows);
    Console::SetBufferSize(cols, rows);
    Console::CursorVisible = false;
}

void goToXY(int x, int y) {
    Console::SetCursorPosition(x, y);
}

void printSquares(int x, int y, int d, int q, char c) {

    //pintar cuadrado izquierdo
    for (int i = x; i <= x + 3; i++){goToXY(i, y);cout << c;}
    for (int i = x; i <= x + 3; i++){goToXY(i, y + 3); cout << c;}

    for (int j = y; j <= y + 3; j++) { goToXY(x, j); cout << c; }
    for (int j = y; j <= y + 3; j++) { goToXY(x + 3, j); cout << c; }

    if (q == 2) {
        //pintar cuadrado derecho
        x += d;
        for (int i = x; i <= x + 3; i++) { goToXY(i, y); cout << c; }
        for (int i = x; i <= x + 3; i++) { goToXY(i, y + 3); cout << c; }

        for (int j = y; j <= y + 3; j++) { goToXY(x, j); cout << c; }
        for (int j = y; j <= y + 3; j++) { goToXY(x + 3, j); cout << c; }
    }

}

int main()
{

    initialSettings();

    int n = -1;
    do
    {
        cout << "Ingresa un numero: ";
        cin >> n;
    } while (!(n >= 1 && n <= 5));

    if (n >= 1) printSquares(4 * 0, 4 * 1, 12 + 4, 2, '1');
    if (n >= 2) printSquares(4 * 1, 4 * 2, 4 + 4, 2, '2');
    if (n >= 3) printSquares(4 * 2, 4 * 3, 0 + 4, 1, '3');
    if (n >= 4) printSquares(4 * 1, 4 * 4, 4 + 4, 2, '4');
    if (n >= 5)  printSquares(4 * 0, 4 * 5, 12 + 4, 2, '5');

    cin.get();
    cin.ignore();
    return 0;
}