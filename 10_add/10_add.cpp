/*
Додаткові задачі: 3 (5)
Дано текстовий файл із речень української мови. Написати програму, що аналізує
текст і виводить таблицю про число входжень кожного символу алфавіту до тексту.
*/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

ifstream fin;
ofstream fout;

int find(string name, char ch, char sb, char bb);
void help_ukr(string name, char ch, char sb, char bb, char letter);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string file = "file.txt";
    fout.open(file);

    if (!fout.is_open())
    {
        cout << "Файл не відкрився";
        return 0;
    }
    cout << "Введіть речення (останній рядок - #): \n";
    string get;
    getline(cin, get);
    while (get != "#") {
        fout << get << endl;
        getline(cin, get);
    }
    fout.close();

    char ch = 0;
    char sb = 'а';
    char bb = 'А';
    char letter = 0;
    for (int i = 0; i < 32; i++)
    {
        if (sb == 'ъ' || sb == 'ы' || sb == 'э') {
            sb++;
            bb++;
        }
        else {
            cout << "\nКількість букв " << bb << ": " << find(file, ch, sb, bb);
            switch (sb) {
            case 'г': letter = 'ґ'; help_ukr(file, ch, sb, bb, letter); break;
            case 'е': letter = 'є'; help_ukr(file, ch, sb, bb, letter); break;
            case 'и': letter = 'і'; help_ukr(file, ch, sb, bb, letter); break;
            }
            sb++;
            bb++;
        }
    }

}

int find(string name, char ch, char sb, char bb) {
    fin.open(name);
    int kilk = 0;
    while (fin.get(ch)) {
        if (ch == sb || ch == bb) {
            kilk++;
        }
    }
    fin.close();
    return kilk;
}

void help_ukr(string name, char ch, char sb, char bb, char letter) {
    char help_s = sb;
    char help_b = bb;
    sb = letter;
    bb = letter;
    cout << "\nКількість букв " << bb << ": " << find(name, ch, sb, bb);
    if (sb == 'і') {
        sb = 'ї';
        bb = 'Ї';
        cout << "\nКількість букв " << bb << ": " << find(name, ch, sb, bb);
    }
    sb = help_s;
    bb = help_b;
}