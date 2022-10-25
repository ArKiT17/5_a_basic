/*Створити заголовковий файл, що реалізує операції над стеком: добавлення та
вилучення елементів, очищення стеку, виведення даних на екран. Продемонструвати
можливості модуля на прикладі роботи зі стеком.*/

struct element {
	int data;
	element* next;
};
typedef element* ptr;

void Add_num(ptr& head, int z){
	ptr help;
	help = new element;
	help->data = z;
	help->next = head;
	head = help;
}

void Del_num(ptr& head) {
	ptr x;
	x = head;
	head = head->next;
	free(x);
}

void Free_num(ptr& head) {
	while (head) {
		ptr x;
		x = head;
		head = head->next;
		free(x);
	}
}

void Print_num(ptr head) {
	if (!head)
		std::cout << "Черга порожня.";
	else {
		while (head) {
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}
}