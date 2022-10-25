/*Створити файл структур, полями якої є відомості про врожай у фермерському
господарстві: назва посівної культури, рік посіву, урожайність (у відсотках). Вивести
на екран відомості про врожай за 2015 рік.*/	//(можна шукати будь-який рік)

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

struct farm {
	string name;
	int year;
	double percent;
};

farm fill();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin;
	ofstream fout;

	fout.open("File.txt", ios::binary);
	if (!fout.is_open()) {
		cout << "Файл не відкрився";
		return 0;
	}
	int count = 0;
	farm out;
	cout << "Введіть дані (остання назва посіву - #)\n";
	out = fill();
	while (out.name != "#") {
		fout.write((char*)&out, sizeof(farm));
		count++;
		out = fill();
	}
	fout.close();
	fin.open("File.txt", ios::binary);
	if (!fin.is_open()) {
		cout << "Файл не відкрився";
		return 0;
	}
	int need;
	cout << "Введіть рік, відомості про який Вам потрібні: ";
	cin >> need;
	farm in;
	for (int i = 0; i < count; i++) {
		fin.read((char*)&in, sizeof(farm));
		if (in.year == need) {
			cout << "Назва посівної культури: " << in.name << endl;
			cout << "Рік посіву: " << in.year << endl;
			cout << "Урожайність: " << in.percent << " \n\n";
		}
	}
	fin.close();
}

farm fill() {
	farm a;
	cout << "Введіть назву посівної культури: ";
	getline(cin, a.name);
	cout << "Введіть рік посіву: ";
	cin >> a.year;
	cout << "Введіть урожайність (у відсотках): ";
	cin >> a.percent;
	cin.ignore(1, EOF);
	return a;
}