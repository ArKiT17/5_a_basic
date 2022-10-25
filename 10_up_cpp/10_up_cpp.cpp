/*
2) Дано текстовий файл, елементами якого є дійсні числа a1, a2, a3, ..., an. Створити файл,
елементами якого будуть числа a1^2, a1 * a2, a1 * a3, a1 * a4, ..., a1 * an.
*/

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

    fout.open("start.txt");
    if (!fout.is_open())
    {
        cout << "Файл не відкрився";
        return 0;
    }

    double num;
    cout << "Введіть декілька дійсних чисел (останнє число 999): ";
    cin >> num;
    while (num != 999)
    {
        fout << num << " ";
        cin >> num;
    }
    fout.close();

    fout.open("end.txt");
    if (!fout.is_open())
    {
        cout << "Файл не відкрився";
        return 0;
    }
    fin.open("start.txt");
    if (!fin.is_open())
    {
        cout << "Файл не відкрився";
        return 0;
    }

    double first;
    fin >> first;
    fin.seekg(0);
    double start_num;
    fin >> start_num;
    while (!fin.eof())
    {
        fout << first * start_num << endl;
        fin >> start_num;
    }

    fout.close();
    fin.close();

    return 0;
}
