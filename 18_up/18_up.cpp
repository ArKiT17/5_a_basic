/* Дано текстовий файл, який містить латинські літери та цифри (1..9). Цифра означає
кількість кроків, на які треба повернутися при перегляді файлу, і вилучити
відповідний символ. Вивести перетворений текст. */

#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

struct element {
	char sum;
	element* next;
	element* prev;
};
typedef element* ptr;

ptr Del(ptr cur);
void Print(ptr head, int k);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream fout;
	fout.open("File.txt");
	if (!fout.is_open()) {
		cout << "Помилка відкриття файлу";
		return 0;
	}
	string line;
	cout << "Введіть рядок файлу: ";
	cin >> line;	//не використовуючи пробілів - умова задачі
	fout << line;
	fout.close();

	ptr head, cur;
	head = new element;
	head->sum = ' ';
	head->next = head;
	head->prev = head;

	ifstream fin;
	fin.open("File.txt");
	if (!fin.is_open()) {
		cout << "Помилка відкриття файлу";
		return 0;
	}
	char a;
	int count = 0;
	fin.get(a);
	cur = head->next;
	ptr h;
	h = new element;
	h->sum = a;
	h->next = cur->next;
	h->prev = cur;
	cur->next->prev = h;
	cur->next = h;
	cur = h;
	count++;
	fin.get(a);
	while (!fin.eof()) {
		h = new element;
		h->sum = a;
		h->next = cur->next;
		h->prev = cur;
		cur->next->prev = h;
		cur->next = h;
		cur = h;
		count++;
		fin.get(a);
	}
	fin.close();
	head = Del(head);
	cur = head;
	int index, i = 0, p = 0;
	ptr del;
	while (i < count) {
		if (cur->sum >= '0' && cur->sum <= '9') {
			index = cur->sum - '0';
			del = cur;
			if (cur->sum == '0')
				cur = cur->next;
			for (int j = 0; j < index; j++)
				del = del->prev;
			del = Del(del);
			p++;
		}
		cur = cur->next;
		i++;
	}
	head = cur;
	Print(head, count - p);
}

ptr Del(ptr cur) {
	ptr help = cur;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	cur = cur->next;
	delete help;
	return cur;
}

void Print(ptr head, int k) {
	ptr help;
	help = head;
	for (int i = 0; i < k; i++) {
		cout << help->sum;
		help = help->next;
	}
	cout << endl;
}