#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

using namespace std;
int i;
double x, y, PI = 3.141592653589793;
void line()
{
    for (int i = 0; i < 29; i++) {
        cout << "_";
    }
    cout << endl;
}

double func(double x) {
    if (x <= 0) {
        return 1;
    }
    else if (x > 0 && x < PI) {
        return cos(x);
    }
    else return -1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x, y;
    cout << "Таблиця значень функції" << endl;
    line();
    cout << "|      X      |      Y      |" << endl;
    line();
    for (int i = 0; i <= 20; i++) {
        x = -PI / 2 + i * PI / 10;
        y = func(x);
        if (x < 0)
            cout << "|   ";
        else cout << "|    ";
        cout << fixed << setprecision(4) << x;
        if (y < 0)
            cout << "   |   ";
        else cout << "   |    ";
        cout << fixed << setprecision(4) << y << "   |" << endl;
    }
    return 0;
}
