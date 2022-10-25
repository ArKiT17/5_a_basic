#include <iostream>
#include <Windows.h>

using namespace std;

int n, m, k, sum;

void fun()
{
    k++;
    sum += (m % 10);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введіть кількість чисел" << endl;
    cin >> n;
    cout << "Введіть " << n;
    if (n % 100 > 9 && n % 100 < 20) cout << " чисел" << endl;
    else
        switch (n % 10)
        {
        case 1: cout << " число" << endl; break;
        case 2:
        case 3:
        case 4: cout << " числа" << endl; break;
        default: cout << " чисел" << endl;
        }
    for (int i = 0; i < n; i++) {
        cin >> m;
        cout << m;
        k = sum = 0;
        while (m > 0) {
            fun();
            m /= 10;
        }
        cout << " " << k << " " << sum << endl;
    }
}

