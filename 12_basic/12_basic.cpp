#include <iostream>
#include <Windows.h>
using namespace std;

int fact(int a) {
    if (a == 0) return 1;
    return a * fact(a - 1);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m, k, f;
    cout << "Вираз: F=m!-k!\nВведіть \"m\" та \"k\": ";
    cin >> m >> k;
    cout << "F = " << fact(m)-fact(k);
}