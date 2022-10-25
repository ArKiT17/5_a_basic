/*Створити файл структур із полями: прізвище студента, оцінки за сесію. За один
перегляд файлу надрукувати спочатку прізвища всіх студентів, які склали сесію на
відмінно, потім – без трійок, далі – без двійок, нарешті – мають заборгованість (зі
збереженням початкового порядку в кожній з цих груп у файлі).*/

#include <iostream>
#include <Windows.h>
#include <fstream>
#define MARK 6 //кількість оцінок

using namespace std;

struct student {
	string name;
	int mark[MARK];
	student* next;
};
typedef student* ptr;

int FillFile();
void Add(ptr& head, ptr& tail, student help);
void Del(ptr& head);
void Print(ptr head);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count = FillFile();
	ifstream fin;
	fin.open("File.txt", ios::binary);
	if (!fin.is_open()) {
		cout << "Помилка відкриття файлу";
		exit(1);
	}
	ptr head5 = NULL, tail5 = NULL;
	ptr head4 = NULL, tail4 = NULL;
	ptr head3 = NULL, tail3 = NULL;
	ptr head2 = NULL, tail2 = NULL;

	student help;
	int min;
	for (int i = 0; i < count; i++) {
		fin.read((char*)&help, sizeof(student));
		min = 10;
		for (int j = 0; j < MARK; j++)
			if (help.mark[j] < min)
				min = help.mark[j];
		switch (min) {
		case 5: Add(head5, tail5, help); break;
		case 4: Add(head4, tail4, help); break;
		case 3: Add(head3, tail3, help); break;
		case 2: Add(head2, tail2, help); break;
		case 1: Add(head2, tail2, help); break;
		}
	}
	fin.close();
	cout << "Відмінники: ";
	if (head5)
		Print(head5);
	else
		cout << "відсутні\n";
	cout << "Без трійок: ";
	if (head4)
		Print(head4);
	else
		cout << "відсутні\n";
	cout << "Без двійок: ";
	if (head3)
		Print(head3);
	else
		cout << "відсутні\n";
	cout << "Мають заборгованість: ";
	if (head2)
		Print(head2);
	else
		cout << "відсутні\n";
	exit (1);
}

int FillFile() {
	int c = 0;
	ofstream fout;
	fout.open("File.txt", ios::binary);
	if (!fout.is_open()) {
		cout << "Помилка відкриття файлу";
		exit(1);
	}
	student help;
	cout << "Введіть дані (останнє прізвище - #)\n";
	while (true) {
		cout << "Введіть прізвище учня: ";
		cin >> help.name;
		if (help.name == "#")
			break;
		c++;
		cout << "Введіть " << MARK << " оцінок: ";
		for (int i = 0; i < MARK; i++)
			cin >> help.mark[i];
		fout.write((char*)&help, sizeof(student));
	}
	fout.close();
	return c;
}

void Add(ptr& head, ptr& tail, student help) {
	ptr h = new student;
	h->name = help.name;
	for (int i = 0; i < MARK; i++)
		h->mark[i] = help.mark[i];
	h->next = NULL;
	if (!head) {
		head = h;
		tail = h;
	}
	else {
		tail->next = h;
		tail = h;
	}
}

void Del(ptr& head) {
	ptr h = head;
	head = head->next;
	delete h;
}

void Print(ptr head) {
	while (head != NULL) {
		cout << head->name << "\t";
		Del(head);
	}
	cout << endl;
}