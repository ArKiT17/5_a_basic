#include <iostream>
#include <Windows.h>
#include <string>
#define N 10
using namespace std;

struct student {
    string name;
    string surname;
    int date[3];
};

int mis(string month);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    student stu[N];
    string month;
    int month_int = -1;
    cout << "Кількість учнів - " << N << "\n\n";
    for (int i = 0; i < N; i++) {       //введення інформації
        cout << "Введіть прізвище та ім'я учня: ";
        cin >> stu[i].surname;
        cin >> stu[i].name;
        cout << "Введіть дату народження учня (дд мм рррр): ";
        for (int j = 0; j < 3; j++)
            cin >> stu[i].date[j];
    }
    cout << endl;
    while (month_int == -1) {
        cout << "Введіть місяць, дні народження якого Вам потрібні: ";
        cin >> month;
        month_int = mis(month);
        if (month_int == -1) {
            cout << "Місяць введений неправильно\n";
        }
    }

    student help;       //сортування за алфавітом
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - 1; j++)
            if ((stu[j].surname) > (stu[j + 1].surname)) {
                help = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = help;
            }

    int k = 0;      //виведення інформації
    for (int i = 0; i < N; i++) {
        if (stu[i].date[1] == month_int) {
            k = 1;
            cout << stu[i].surname << "\t" << stu[i].name << "\t";
            for (int j = 0; j < 3; j++)
                cout << stu[i].date[j] << " ";
        }
    }
    if (k == 0) cout << "\nНе існує учнів, які мають день народження в заданому місяці";
}

int mis(string month) {     //корвертація місяця в число
    if (month == "Січень" || month == "січень")  return 1;
    if (month == "Лютий" || month == "лютий")    return 2;
    if (month == "Березень" || month == "березень")  return 3;
    if (month == "Квітень" || month == "квітень")  return 4;
    if (month == "Травень" || month == "травень")  return 5;
    if (month == "Червень" || month == "червень")  return 6;
    if (month == "Липень" || month == "липень")  return 7;
    if (month == "Серпень" || month == "серпень")  return 8;
    if (month == "Вересень" || month == "вересень")  return 9;
    if (month == "Жовтень" || month == "жовтень")  return 10;
    if (month == "Листопад" || month == "листопад")  return 11;
    if (month == "Грудень" || month == "грудень")  return 12;
    return -1;
}