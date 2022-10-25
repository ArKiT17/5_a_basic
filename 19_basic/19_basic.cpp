/* 2. Упорядкувати послідовність цілих чисел за зростанням. */

#include <iostream>
#include <Windows.h>

using namespace std;

struct tree {
	int data;
	struct tree* left;
	struct tree* right;
};
typedef tree* ptr;

void Find(ptr* proot, int elem);
void Print(ptr root);

int main()
{
	SetConsoleOutputCP(1251);
	cout << "Введіть послідовність цілих чисел (останнє число 999): ";
	int a;
	cin >> a;
	ptr root = NULL;
	while (a != 999) {
		Find(&root, a);
		cin >> a;
	}
	Print(root);
}

void Find(ptr* root, int elem) {
	if (*(root) == NULL) {
		*root = new tree;
		(*root)->data = elem;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
		if (elem < (*root)->data)
			Find(&((*root)->left), elem);
		else
			Find(&((*root)->right), elem);

}

void Print(ptr root) {
	if (root != NULL) {
		Print(root->left);
		cout << root->data << " ";
		Print(root->right);
	}
}