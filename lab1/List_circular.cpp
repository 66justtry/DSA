#include "Header.h"
#include <iostream>
using namespace std;

void List_circular::AddEnd(Data* new_data) {
	if (head == NULL) {
		Node* new_node = new Node();
		new_node->prev = new_node;
		new_node->next = new_node;
		new_node->data = new_data;
		head = new_node;
		tail = new_node;
		count++;
		return;
	}
	Node* new_node = new Node();
	new_node->prev = tail;
	new_node->next = head;
	tail->next = new_node;
	head->prev = new_node;
	new_node->data = new_data;
	tail = new_node;
	count++;
}
void List_circular::AddBegin(Data* new_data) {
	if (head == NULL) {
		Node* new_node = new Node();
		new_node->prev = new_node;
		new_node->next = new_node;
		new_node->data = new_data;
		head = new_node;
		tail = new_node;
		count++;
		return;
	}
	Node* new_node = new Node();
	new_node->prev = tail;
	new_node->next = head;
	new_node->data = new_data;
	head->prev = new_node;
	tail->next = new_node;
	head = new_node;
	count++;
}
void List_circular::Clear() {
	if (head == NULL)
		return;
	Node* cur = head;
	for (int i = 0; i < count - 1; i++) {
		delete cur->data;
		cur = cur->next;
		delete cur->prev;
	}
	delete cur->data;
	delete cur;
	head = NULL;
	tail = NULL;
	count = 0;
}
void List_circular::Delete(int num) {
	Node* cur = head;
	if (num > count)
		return;
	for (int i = 1; i < num; i++)
		cur = cur->next;
	if ((cur == head) && (cur == tail)) {
		head = NULL;
		tail = NULL;
	}
	else if (cur == head) {
		cur->next->prev = tail;
		head = cur->next;
	}
	else if (cur == tail) {
		cur->prev->next = head;
		tail = cur->prev;
	}
	else {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}
	delete cur->data;
	delete cur;
	count--;
}
void List_circular::Swap(int num1, int num2) {
	Node* p1 = head;
	for (int i = 1; i < num1; i++) {
		p1 = p1->next;
	}
	Node* p2 = head;
	for (int i = 1; i < num2; i++) {
		p2 = p2->next;
	}
	if ((p1->next != p2) && (p1->prev != p2)) {
		cout << "Это не соседние элементы!\n";
		return;
	}
	if ((num1 > count) || (num2 > count)) {
		cout << "Неправильно введен номер элемента!\n";
		return;
	}
	if (num1 == num2)
		return;

	if ((p1 == head) && (p2 == tail)) {
		p1->next->prev = p2;
		p2->prev->next = p1;
		p2->next = p1->next;
		p1->prev = p2->prev;
		p1->next = p2;
		p2->prev = p1;
		head = p2;
		tail = p1;
		return;
	}
	else if ((p2 == head) && (p1 == tail)) {
		p2->next->prev = p1;
		p1->prev->next = p2;
		p1->next = p2->next;
		p2->prev = p1->prev;
		p2->next = p1;
		p1->prev = p2;
		head = p1;
		tail = p2;
		return;
	}



	if (p1 == head) {
		p1->next = p2->next;
		p2->next->prev = p1;
		p1->prev = p2;
		p2->next = p1;
		p2->prev = tail;
		tail->next = p2;
		head = p2;
		return;
	}
	if (p2 == head) {
		p2->next = p1->next;
		p1->next->prev = p2;
		p2->prev = p1;
		p1->next = p2;
		p1->prev = tail;
		tail->next = p1;
		head = p1;
		return;
	}
	if (p1 == tail) {
		p2->prev->next = p1;
		p1->prev = p2->prev;
		p1->next = p2;
		p2->prev = p1;
		p2->next = head;
		head->prev = p2;
		tail = p2;
		return;
	}
	if (p2 == tail) {
		p1->prev->next = p2;
		p2->prev = p1->prev;
		p2->next = p1;
		p1->prev = p2;
		p1->next = head;
		head->prev = p1;
		tail = p1;
		return;
	}



	p1->prev->next = p2;
	p1->next = p2->next;
	p2->prev = p1->prev;
	p2->next = p1;
	p1->next->prev = p1;
	p1->prev = p2;
}
List_circular* List_circular::AddList(List_circular* list1, List_circular* list2) {
	List_circular* new_list = new List_circular;
	Node* cur = list1->head;
	for (int i = 0; i < list1->count; i++) {
		new_list->AddEnd(cur->data);
		cur = cur->next;
	}
	cur = list2->head;
	for (int i = 0; i < list2->count; i++) {
		new_list->AddEnd(cur->data);
		cur = cur->next;
	}
	//list1->Clear();
	//list2->Clear();
	return new_list;
}
void List_circular::Show() {
	ofstream out("out.txt");

	Node* cur = head;
	if (head == NULL) {
		cout << "Список пока пустой.\n";
		out.close();
		return;
	}
	cout << "Список:\n";
	for (int i = 0; i < this->count; i++) {
		cout << cur->data->v << "  ";
		out << cur->data->v << "  ";
		cur = cur->next;
	}
	out.close();
}


void menu(List_circular* list) {
	//system("cls");
	list->Show();
	int ch;
	cout << "\n\n";
	cout << "1 - Создать список\n";
	cout << "2 - Добавить элемент\n";
	cout << "3 - Удалить элемент\n";
	cout << "4 - Посчитать кол-во элементов\n";
	cout << "5 - Поменять местами соседние элементы\n";
	cout << "6 - Добавить новый список в конец\n";
	cout << "7 - Очистить список\n";
	cout << "8 - Выход\n";
	cin >> ch;
	if (ch == 1) {
		system("cls");
		list->Clear();
		int n;
		int q;
		cout << "1 - Ввести с клавиатуры\n";
		cout << "2 - Ввести из файла\n";
		cin >> q;
		if (q == 1) {
			cout << "\nКол-во элементов в списке: ";
			cin >> n;
			cout << "Введите " << n << " чисел типа double\n";
			for (int i = 0; i < n; i++) {
				double x;
				cin >> x;
				Data* temp_data = new Data(x);
				list->AddEnd(temp_data);
			}
		}
		else if (q == 2) {
			ifstream in("in.txt");
			for (int i = 0; i < 5; i++) {
				double x;
				in >> x;
				Data* temp_data = new Data(x);
				list->AddEnd(temp_data);
			}
			in.close();
		}

	}
	else if (ch == 2) {
		double x;
		cout << "Введите новый элемент типа double: ";
		cin >> x;
		Data* temp_data = new Data(x);
		list->AddEnd(temp_data);
	}
	else if (ch == 3) {
		int n;
		cout << "Номер элемента: ";
		cin >> n;
		list->Delete(n);
	}
	else if (ch == 4) {
		cout << "\nЭлементов в списке: " << list->count << endl;
	}
	else if (ch == 5) {
		int n1, n2;
		cout << "Элемент 1: ";
		cin >> n1;
		cout << "Элемент 2: ";
		cin >> n2;
		list->Swap(n1, n2);
	}
	else if (ch == 6) {
		List_circular* list_temp = new List_circular;
		int n;
		int q;
		cout << "1 - Ввести с клавиатуры\n";
		cout << "2 - Ввести из файла\n";
		cin >> q;
		if (q == 1) {
			cout << "\nКол-во элементов в списке: ";
			cin >> n;
			cout << "Введите " << n << " чисел типа double\n";
			for (int i = 0; i < n; i++) {
				double x;
				cin >> x;
				Data* temp_data = new Data(x);
				list_temp->AddEnd(temp_data);
			}
		}
		else if (q == 2) {
			ifstream in("in.txt");
			for (int i = 0; i < 5; i++) {
				double x;
				in >> x;
				Data* temp_data = new Data(x);
				list_temp->AddEnd(temp_data);
			}
			in.close();
		}
		list = list->AddList(list, list_temp);
	}
	else if (ch == 7) {
		list->Clear();
	}
	else if (ch == 8) {
		return;
	}

	system("pause");
	menu(list);
}