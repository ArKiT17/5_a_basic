/*Створити програму, яка зі списків слів L1, L2 формує новий список L, заносячи до
нього по одному разу ті слова, що містяться хоча б в одному зі списків L1 і L2.*/

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

struct element {
	string word;
	element* next;
};
typedef element* ptr;

ptr inFirst(ptr head, string x);
ptr fill_list(ptr head);
ptr fill_main(ptr head1, ptr head2, ptr head);
void print(ptr head);
ptr wh(ptr headA, ptr headB);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ptr head1 = NULL, head2 = NULL, head = NULL;
	cout << "Введіть слова першого списку: ";
	head1 = fill_list(head1);
	cout << "Введіть слова другого списку: ";
	head2 = fill_list(head2);
	cout << "Загальні слова: ";
	head = fill_main(head1, head2, head);
	print(head);
	return 0;
}

void print(ptr head) {
	ptr cur = head;
	while (cur != NULL) {
		cout << cur->word << " ";
		cur = cur->next;
	}
}

ptr fill_main(ptr head1, ptr head2, ptr head) {
	head = new element;
	head->word = head1->word;
	head->next = NULL;
	head = wh(head, head2);	//L = L1
	head = wh(head, head1);	//L = L1+L2
	return head;
}

ptr wh(ptr headA, ptr headB) {
	ptr cur, curM;
	bool flag;
	curM = headA;
	cur = headB;
	while (cur != NULL) {
		flag = true;
		while (curM != NULL) {
			if (curM->word != cur->word)
				curM = curM->next;
			else {
				flag = false;
				curM = curM->next;
			}
		}
		if (flag)
			headA = inFirst(headA, cur->word);
		cur = cur->next;
		curM = headA;
	}
	return headA;
}

ptr fill_list(ptr head) {
	string help;
	getline(cin, help);
	int lenth = help.length();
	int first = help.find_first_not_of(" ", 0);
	int last = help.find_first_of(" ", first + 1);
	string word = help.substr(first, last - first);
	head = inFirst(head, word);
	while (last != -1) {
		first = first = help.find_first_not_of(" ", last + 1);
		last = help.find_first_of(" ", first + 1);
		word = help.substr(first, last - first);
		head = inFirst(head, word);

	}
	return head;
}

ptr inFirst(ptr head, string x) {
	ptr h;
	h = new element;
	h->word = x;
	h->next = head;
	head = h;
	return head;
}