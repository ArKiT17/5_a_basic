//	Дано рядок. Перевірити, чи є він правильним записом формули такого виду:
//	<формула>::=<терм>|<терм>+<формула>|<терм>-<формула>
//	<терм>::=<ім’я>|(<формула>)|[<формула>]|{<формула>}
//	<ім’я>::=x|y|z

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

struct element
{
	char sym; // символ
	element* next; // вказівник
};
typedef element* ptr;

ptr In(ptr head, char z);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 0, j;
	bool flag = true;
	ptr head = nullptr;
	ptr cur;
	int ip, ik;         // індекс початку числа в формулі
	char op;           // змінна для операції

	string formula; // Змінна для формули, яка є рядком
	string slovo;    //


	cout << "Введiть формулу" << endl;
	cin >> formula;
	int length = formula.length();
	if ((formula[i] >= 'x') && (formula[i] <= 'z')) { //один символ
		i++;
		if (i == length) {
			cout << "Значення формули" << endl;
			cout << formula << endl;
		}
		else
			flag = 0;
	}
	else { // скаладна булова
		while (i < length) {
			// і-й символ формули є відкритою дужкою. 
			if (formula[i] == '(' || formula[i] == '[' || formula[i] == '{') {
				head = In(head, formula[i]); // Заносимо '(' в стек символів
				i++;
				if ((formula[i] >= 'x') && (formula[i] <= 'z')) {
					slovo = formula[ip];    // слово рядка, яке є числом
					head = In(head, 't'); // Заносимо 't' в стек символів
					i++;
					if ((formula[i] == '+') || (formula[i] == '-')) {
						head = In(head, formula[i]); // Заносимо операцію в стек символів
						i++;
					}
					else     // і-й символ формули - закрита дужка  
						if (formula[i] == ')' || formula[i] == ']' || formula[i] == '}')
						{
							// визначаємо довжину стека
							j = 0;     //лічильник для підрахунку елементів стека символів
							cur = head;
							while (cur) {
								j++;
								cur = cur->next;
							}
							if (j >= 2)  //стек містить не менше 4 символи
							{
								// Перевіряємо, чи в стеку, починаючи з вершини, містяться
								// символи в такому порядку - 't', один із символів +,-,*,
								// знову 't', нарешті '('.
								if ((head->sym == 't') && (head->next->next->sym == 't') &&
									(head->next->next->next->sym == '(')) {
									flag = 1; // Успішно розпізнали формулу
									i = length; // Завершуємо розпізнавання
								}
								else {
									flag = 0; // Формула записана невірно
									i = length; // Завершуємо розпізнавання
								}
							}
							else {
								flag = 0; // Формула записана невірно
								i = length; // Завершуємо розпізнавання
							}
						}
						else {
							flag = 0; // Формула записана невірно
							i = length; // Завершуємо розпізнавання
						}
				}
				else {
					flag = 0;
					i = length;
				}
			}
			else {
				flag = 0;
				i = length;
			}
				
		} // Кінець while (i<length)
	}

	if (!flag) // Виведення результату аналізу формули
		cout << "Формула записана не вiрно" << endl;
}

ptr In(ptr head, char z)
{
	ptr x;
	x = new element;
	x->sym = z;
	x->next = head;
	head = x;
	return head;
}