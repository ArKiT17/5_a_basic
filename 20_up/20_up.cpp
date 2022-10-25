/* Створити заголовковий файл, що реалізує операції над стеком: добавлення та
вилучення елементів, очищення стеку, виведення даних на екран. Продемонструвати
можливості модуля на прикладі роботи зі стеком. */

#include <iostream>
#include <Windows.h>
#include "Stack.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	cout << "Введіть декілька цілих чисел (останнє \"999\"): ";
	ptr head = NULL;
	int a;
	cin >> a;
	while (a != 999) {
		Add_num(head, a);
		cin >> a;
	}
	cout << "-- Ініціалізація черги --\n";
	Print_num(head);
	cout << "-- Видалення елементу з черги --\n";
	if (head)
		Del_num(head);
	Print_num(head);
	cout << "-- Очищення черги --\n";
	Free_num(head);
	Print_num(head);
}