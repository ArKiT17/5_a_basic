/* Створити файл записів із полями: прізвище, номер телефону, заборгованість. За один
перегляд файлу вивести прізвища абонентів і номери телефонів, у яких заборгованість
найбільша. */

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

struct pearson {
	string surname;
	string tel;
	int borg;
	pearson* next;
};
typedef pearson* ptr;

void Add(ptr& head, string name, string tel, int borg);
void Free(ptr& head);
void Print(ptr head);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream fout;
	fout.open("File.txt", ios::binary);
	if (!fout.is_open()) {
		cout << "Файл не відкрився";
		return 0;
	}
	pearson a;
	int num = 0;
	cout << "Введіть дані (останнє прізвище '#')\n";
	while (true) {
		cout << "Введіть прізвище: ";
		cin >> a.surname;
		if (a.surname == "#")
			break;
		cout << "Введіть номер телефону: ";
		cin.ignore(1, EOF);
		getline(cin, a.tel);
		cout << "Введіть борг: ";
		cin >> a.borg;
		fout.write((char*)&a, sizeof(pearson));
		num++;
	}
	fout.close();
	ifstream fin;
	fin.open("File.txt", ios::binary);
	if (!fin.is_open()) {
		cout << "Файл не відкрився";
		return 0;
	}
	int max = -1;
	ptr head = NULL;
	for (int i = 0; i < num; i++) {
		fin.read((char*)&a, sizeof(pearson));
		if (a.borg > max) {
			max = a.borg;
			Free(head);
		}
		if (a.borg == max)
			Add(head, a.surname, a.tel, a.borg);
	}
	fin.close();
	Print(head);
}

void Add(ptr& head, string name, string tel, int borg) {
	ptr help = new pearson;
	help->surname = name;
	help->tel = tel;
	help->borg = borg;
	help->next = head;
	head = help;
}

void Free(ptr& head) {
	while (head) {
		ptr h = head;
		head = head->next;
		free(h);
	}
}

void Print(ptr head) {
	while (head) {
		cout << head->surname << "\t";
		cout << head->tel << endl;
		head = head->next;
	}
}