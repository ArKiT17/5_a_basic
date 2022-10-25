//Дано файл f натуральних чисел. Записати у файл g усі прості числа з файлу f у порядку спадання.

#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream fout;
    ifstream fin;

    fout.open("f.txt", ios::binary);
    if (!fout.is_open()) {
        cout << "Файл не відкрився";
        return 0;
    }

    cout << "Введіть декілька натуральних чисел (останнє число 999): \n";
    double num;
    cin >> num;
    while (num != 999) {
        fout.write((char*)&num, sizeof(num));
        cin >> num;
    }
    fout.close();
    
    fin.open("f.txt", ios::binary);
    if (!fin.is_open()) {
        cout << "Файл не відкрився";
        return 0;
    }

    int arr[64] = { 0, };
    double element = 0;
    int last = 0;
    while (!fin.eof()) {
        element = 0;
        fin.read((char*)&element, sizeof(element));
        bool t = true;
        for (int i = 2; i <= element / 2; i++) {
            double element_d = element / i;
            if (element_d - (int)element / i == 0) {
                t = false;
                break;
            }
        }
        if (t && element != 0) {
            arr[last] = element;
            last++;
        }
    }
    fin.close();
    last--;
    for (int i = 0; i < last; i++) {
        for (int j = 0; j < last - i; j++)
            if (arr[j] < arr[j + 1]) {
                int help = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = help;
            }
    }

    fout.open("g.txt", ios::binary);
    if (!fout.is_open()) {
        cout << "Файл не відкрився";
        return 0;
    }
    fout.write((char*)&arr, sizeof(arr));
    fout.close();
    cout << "Числа з другого файлу: ";
    int print = 0;

    fin.open("g.txt", ios::binary);
    if (!fin.is_open()) {
        cout << "Файл не відкрився";
        return 0;
    }
    for (int i = 0; i < last + 1; i++) {
        fin.read((char*)&print, sizeof(int));
        cout << print << " ";
    }
    fin.close();
    return 0;
}
