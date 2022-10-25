#include <iostream>
#include <Windows.h>

using namespace std;

int a, a1, a2, a3, a4;

bool real() {
    if (a1 + a2 == a3 + a4)
        return true;
    else
        return false;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введiть чотиризначне число: ";
    cin >> a;
    a1 = a / 1000;
    a2 = a / 100 % 10;
    a3 = a / 10 % 10;
    a4 = a % 10;
    if (real() == true)
        cout << "Сума перших двох цифр даного числа РIВНА сумi двох його останнiх цифр";
    else
        cout << "Сума перших двох цифр даного числа НЕ РIВНА сумi двох його останнiх цифр";
}