#include "Header.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Queue::Queue() {
	head = NULL;
	tail = NULL;
}

void Queue::Push(Element_queue* temp) {
	if (head == NULL) {
		head = temp;
	}
	else {
		tail->prev = temp;
	}
	temp->next = tail;
	tail = temp;
}

void Queue::Pop() {
	if (head == NULL)
		return;
	if (head == tail) {
		Element_queue* temp = head;
		head = NULL;
		tail = NULL;
		delete temp;
	}
	else {
		Element_queue* temp = head;
		head->prev->next = NULL;
		head = head->prev;
		delete temp;
	}
}

void Queue::Clear() {
	while (head != NULL) {
		Pop();
	}
}

int Queue::Count() {
	Queue* q = this;
	int k = 0;
	Queue* temp = new Queue;
	while (head != NULL) {
		temp->Push(new Element_queue(q->head->data));
		q->Pop();
		k++;
	}
	while (temp->head != NULL) {
		q->Push(new Element_queue(temp->head->data));
		temp->Pop();
	}
	delete temp;
	return k;
}

void Queue::FileIn() {
	ifstream in("in_queue.txt");
	char a;
	for (int i = 0; i < 5; i++) {
		Element_queue* temp = new Element_queue;
		in >> a;
		temp->data = a;
		Push(temp);
	}
	in.close();
}

void Queue::Out() {
	ofstream out("out_queue.txt");
	int k = Count();
	cout << "Очередь:\n";
	out << "Очередь:\n";
	if (k == 0) {
		cout << "Очередь пустая...\n";
		out << "Очередь пустая...\n";
		out.close();
		return;
	}
	for (int i = 0; i < k; i++) {
		cout << setw(3) << head->data;
		out << setw(3) << head->data;
		Push(new Element_queue(head->data));
		Pop();
	}
	cout << "\n<---------------\n";
	cout << "head--------tail\n";
	cout << endl;
	out << "\n<---------------\n";
	out << "head--------tail\n";
	out << endl;
	out.close();
}

double Queue::Middle() {
	int k = Count();
	if (k == 0)
		return 0;
	double sum = 0;
	for (int i = 0; i < k; i++) {
		sum += (int)head->data - 48;
		Push(new Element_queue(head->data));
		Pop();
	}
	return sum / k;
}

void Queue::FindMax(int& pos, char& symbol) {
	int k = Count();
	if (k == 0) {
		pos = 0;
		symbol = '0';
		return;
	}
	int max = (int)head->data - 48;
	pos = 0;
	Push(new Element_queue(head->data));
	Pop();
	for (int i = 1; i < k; i++) {
		if ((int)head->data - 48 > max) {
			max = int(head->data - 48);
			pos = i;
		}
		Push(new Element_queue(head->data));
		Pop();
	}
	symbol = (char)(max + 48);
}

void Queue::FindMin(int& pos, char& symbol) {
	int k = Count();
	if (k == 0) {
		pos = 0;
		symbol = '0';
		return;
	}
	int min = (int)head->data - 48;
	pos = 0;
	Push(new Element_queue(head->data));
	Pop();
	for (int i = 1; i < k; i++) {
		if ((int)head->data - 48 < min) {
			min = int(head->data - 48);
			pos = i;
		}
		Push(new Element_queue(head->data));
		Pop();
	}
	symbol = (char)(min + 48);
}

void Queue::NextMin() {
	int pos;
	char symbol;
	FindMin(pos, symbol);
	if (pos == 0) {
		cout << "Минимальный элемент - первый.\n";
		return;
	}
	int k = Count();
	for (int i = 0; i < k; i++) {
		if (i == pos - 1)
			cout << head->data << endl;
		Push(new Element_queue(head->data));
		Pop();
	}
}