#include "Header.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std;



void List::AddEnd(Data* new_data) {
	if (head == NULL) {
		Node* new_node = new Node();
		new_node->prev = NULL;
		new_node->next = NULL;
		new_node->data = new_data;
		head = new_node;
		tail = new_node;
		count++;
		return;
	}
	Node* new_node = new Node();
	new_node->prev = tail;
	new_node->next = NULL;
	tail->next = new_node;
	new_node->data = new_data;
	tail = new_node;
	count++;
}
void List::AddBegin(Data* new_data) {
	if (head == NULL) {
		Node* new_node = new Node();
		new_node->prev = NULL;
		new_node->next = NULL;
		new_node->data = new_data;
		head = new_node;
		tail = new_node;
		count++;
		return;
	}
	Node* new_node = new Node();
	new_node->prev = NULL;
	new_node->next = head;
	new_node->data = new_data;
	head->prev = new_node;
	head = new_node;
	count++;
}
void List::Clear() {
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
void List::Delete(int num) {
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
		cur->next->prev = NULL;
		head = cur->next;
	}
	else if (cur == tail) {
		cur->prev->next = NULL;
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
void List::Swap(int num1, int num2) {
	if ((num1 != num2 + 1) && (num2 != num1 + 1)) {
		cout << "Это не соседние элементы!\n";
		return;
	}
	if ((num1 > count) || (num2 > count)) {
		cout << "Неправильно введен номер элемента!\n";
		return;
	}
	if (num1 == num2)
		return;
	Node* p1 = head;
	for (int i = 1; i < num1; i++) {
		p1 = p1->next;
	}
	Node* p2 = head;
	for (int i = 1; i < num2; i++) {
		p2 = p2->next;
	}
	if ((p1 == head) && (p2 == tail)) {
		p1->next = NULL;
		p1->prev = p2;
		p2->next = p1;
		p2->prev = NULL;
		head = p2;
		tail = p1;
		return;
	}
	else if ((p2 == head) && (p1 == tail)) {
		p2->next = NULL;
		p2->prev = p1;
		p1->next = p2;
		p1->prev = NULL;
		head = p1;
		tail = p2;
		return;
	}



	if (p1 == head) {
		p1->next = p2->next;
		p2->next->prev = p1;
		p1->prev = p2;
		p2->next = p1;
		p2->prev = NULL;
		head = p2;
		return;
	}
	if (p2 == head) {
		p2->next = p1->next;
		p1->next->prev = p2;
		p2->prev = p1;
		p1->next = p2;
		p1->prev = NULL;
		head = p1;
		return;
	}
	if (p1 == tail) {
		p2->prev->next = p1;
		p1->prev = p2->prev;
		p1->next = p2;
		p2->prev = p1;
		p2->next = NULL;
		tail = p2;
		return;
	}
	if (p2 == tail) {
		p1->prev->next = p2;
		p2->prev = p1->prev;
		p2->next = p1;
		p1->prev = p2;
		p1->next = NULL;
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
List* List::AddList(List* list1, List* list2) {
	List* new_list = new List;
	Node* cur = list1->head;
	while (1) {
		new_list->AddEnd(cur->data);
		if (cur->next == NULL)
			break;
		cur = cur->next;
	}
	cur = list2->head;
	while (1) {
		new_list->AddEnd(cur->data);
		if (cur->next == NULL)
			break;
		cur = cur->next;
	}
	//list1->Clear();
	//list2->Clear();
	return new_list;
}
void List::Show() {
	ofstream out("out.txt");
	cout << endl;
	Node* cur = head;
	if (head == NULL) {
		cout << "Список пока пустой.\n";
		out.close();
		return;
	}
	cout << "Список:\n";
	while (1) {
		cout << cur->data->v << "  ";
		out << cur->data->v << "  ";
		if (cur->next == NULL)
			break;
		cur = cur->next;
	}
	out.close();
}
	
	
	
	



void menu(List* list) {
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
		//system("cls");
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
		List* list_temp = new List;
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


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	List* list = new List;

	//List_circular* list = new List_circular;

	menu(list);
	list->Clear();
	delete list;

	system("pause");
	return 0;
}