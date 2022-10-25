﻿#include <iostream> //библиотека на ввод-вывод символов
#include <string> //библиотека для работы со строками
#include <Windows.h>  //библиотека для укр языка

using namespace std;  //пространство имён std

struct ychen {  //об'ява структури ychen
    string prizv;   //створення змінної prizv типу рядок 
    int day, month;  //створення змінної "день" та змінної "місяць"
};

int main()
{
    SetConsoleCP(1251); //команда на можливість введення кирилиці
    SetConsoleOutputCP(1251);   //...виведення
    const int m = 5;    //створення константи (не писал #define, чтоб не было одинаково)
    ychen mas[m];   //створення масиву (mas) структур (ychen)
    for (int i = 0; i < m; i++) {  //ініціалізація масиву (саме тут цикл, який бігає по масиву структур для його заповнення)
        cout << "Введіть прізвище учня: ";
        cin >> mas[i].prizv;  //введення прізвища одного учня
        cout << "Введіть число та місяць народження: ";
        cin >> mas[i].day >> mas[i].month;  //введення дня та місяця одного учня
    }
    for (int i = 0; i < m; i++) //цикл звону біжить по всьому масиву...
        if (mas[i].month == 12 || mas[i].month == 1 || mas[i].month == 2)   //...перевіряючи чи взимку у цього учня ДР...
            cout << mas[i].prizv << "\t" << mas[i].day << "\t" << mas[i].month << endl; //...у разі правди - виводить всю іншормацію про учня
}