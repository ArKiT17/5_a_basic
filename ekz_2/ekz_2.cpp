/* Створити файл структур із полями: прізвище студента, оцінки за сесію. За один
перегляд файлу надрукувати спочатку прізвища всіх студентів, які склали сесію на
відмінно, потім – без трійок, далі – без двійок, нарешті – мають заборгованість (зі
збереженням початкового порядку в кожній з цих груп у файлі). */

#include <iostream>
#include <Windows.h>
#include <fstream>
#define N 3

using namespace std;

struct student {
	string name;
	int mark[N];
	student* next;
};
typedef student* ptr;

void Add(ptr& head, ptr& tail, student help);
void Remove(ptr& head);
void Print(ptr head);
void FillFile();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FillFile();
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
	fin.read((char*)&help, sizeof(student));
	while (!fin.eof()) {
		min = 10;
		for (int j = 0; j < N; j++)
			if (help.mark[j] < min)
				min = help.mark[j];
		switch (min) {
		case 5: Add(head5, tail5, help); break;
		case 4: Add(head4, tail4, help); break;
		case 3: Add(head3, tail3, help); break;
		case 2: Add(head2, tail2, help); break;
		case 1: Add(head2, tail2, help); break;
		}
		fin.read((char*)&help, sizeof(student));
	}
	fin.close();
	cout << "\nВідмінники: ";
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
	exit(1);
}

void FillFile() {
	ofstream fout;
	fout.open("File.txt", ios::binary);
	if (!fout.is_open()) {
		cout << "Помилка відкриття файлу";
		exit(1);
	}
	student help;
	cout << "Введіть дані (останнє прізвище - #)\n";
	cout << "Введіть прізвище учня: ";
	cin >> help.name;
	while (help.name != "#") {
		cout << "Введіть " << N << " оцінок: ";
		for (int i = 0; i < N; i++)
			cin >> help.mark[i];
		fout.write((char*)&help, sizeof(student));
		cout << "Введіть прізвище учня: ";
		cin >> help.name;
	}
	fout.close();
}

void Add(ptr& head, ptr& tail, student help) {
	ptr h = new student;
	h->name = help.name;
	for (int i = 0; i < N; i++)
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

void Remove(ptr& head) {
	ptr h = head;
	head = head->next;
	delete h;
}

void Print(ptr head) {
	while (head != NULL) {
		cout << head->name << " ";
		Remove(head);
	}
	cout << endl;
}