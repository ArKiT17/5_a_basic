/*Створити файл структур із полями: назва міста, кількість жителів, площа міста.
Упорядкувати цей файл за не зростанням кількості жителів, а при однаковій кількості,
упорядкувати за не спаданням площі.*/

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

struct city {
    string name;
    int people;
    int area;
};

city fill_struct();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream fin;
    ofstream fout;
    fstream foi;

    fout.open("File.txt", ios::binary);
    if (!fout.is_open()) {
        cout << "Файл не відкрився";
        return 0;
    }
    city a;
    cout << "Введіть данні (останній запис назви - #)\n";
    a = fill_struct();
    int count = 0;
    while (a.name != "#") {
        fout.write((char*)&a, sizeof(city));
        a = fill_struct();
        count++;
    }
    fout.close();

    foi.open("File.txt", ios::in | ios::out | ios::binary);
    if (!foi.is_open()) {
        cout << "Файл не відкрився";
        return 0;
    }
    city h1, h2;
    for (int i = count - 1; i > 0; i--)
        for (int j = 0; j < i; j++) {
            foi.seekg(j * sizeof(city));
            foi.read((char*)&h1, sizeof(city));
            foi.read((char*)&h2, sizeof(city));
            if (h1.people < h2.people || h1.people == h2.people && h1.area > h2.area) {
                foi.seekp(j * sizeof(city));
                foi.write((char*)&h2, sizeof(city));
                foi.write((char*)&h1, sizeof(city));
            }
        }
    foi.close();
    fin.open("File.txt", ios::binary);
    if (!fin.is_open()) {
        cout << "Файл не відкрився";
        return 0;
    }
    for (int i = 0; i < count; i++) {
        city help2;
        fin.read((char*)&help2, sizeof(city));
        cout << "\nМісто: " << help2.name;
        cout << "\nКількість жителів: " << help2.people;
        cout << "\nПлоща: " << help2.area;
    }
    fin.close();
    return 0;
}

city fill_struct() {
    city str;
    cout << "Введіть назву міста: ";
    getline(cin, str.name);
    cout << "Введіть кількість жителів: ";
    cin >> str.people;
    cout << "Введіть площу міста: ";
    cin >> str.area;
    cin.ignore(1, EOF);
    return str;
}