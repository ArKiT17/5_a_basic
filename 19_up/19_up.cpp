/* Користуючись умовою задачі No 1, написати програму, яка друкує дерево-формулу у
вигляді формули. */

#include <iostream>
#include <Windows.h>

using namespace std;

typedef struct tree {
	char sym;
	struct tree* left;
	struct tree* right;
};
typedef tree* treeptr;

treeptr TreeF();
void Print(treeptr root);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	treeptr root;
	cout << "Введiть рядок-формулу: ";
	root = TreeF();
	cout << "Виведення дерева-формули: ";
	Print(root);
	return 0;
}

treeptr TreeF() {
	char c, op;
	treeptr lf, rf, nf;
	cin >> c;
	if (((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9'))) {
		nf = new tree;
		nf->sym = c;
		nf->left = NULL;
		nf->right = NULL;
		return nf;
	}
	else
		if (c == '(') {
			lf = TreeF();
			cin >> op;
			if ((op != '+') && (op != '-') && (op != '*') && (op != '/')) {
				puts("Формула записана невiрно");
				exit(1);
			}
			rf = TreeF();
			nf = new tree;
			nf->sym = op;
			nf->left = lf;
			nf->right = rf;
			cin >> c;
			return nf;
		}
		else {
			puts("Формула записана невiрно");
			exit(1);
		}

}

void Print(treeptr root)
{
	if (root != NULL) {
		Print(root->left);
		cout << root->sym;
		Print(root->right);
	}
}