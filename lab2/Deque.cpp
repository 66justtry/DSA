#include "Header.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Deque::Deque() {
	front = NULL;
	back = NULL;
}

void Deque::Push_front(Element_deque* temp) {
	if (front == NULL) {
		front = temp;
		back = temp;
	}
	else {
		front->next = temp;
		temp->prev = front;
		front = temp;
	}
}

void Deque::Push_back(Element_deque* temp) {
	if (front == NULL) {
		front = temp;
		back = temp;
	}
	else {
		back->prev = temp;
		temp->next = back;
		back = temp;
	}
}

void Deque::Pop_front() {
	if (front == NULL)
		return;
	if (front == back) {
		Element_deque* temp = front;
		front = NULL;
		back = NULL;
		delete temp;
	}
	else {
		front = front->prev;
		delete front->next;
		front->next = NULL;
	}
}

void Deque::Pop_back() {
	if (front == NULL)
		return;
	if (front == back) {
		Element_deque* temp = back;
		front = NULL;
		back = NULL;
		delete back;
	}
	else {
		back = back->next;
		delete back->prev;
		back->prev = NULL;
	}
}

int Deque::Count() {
	Deque* temp = new Deque;
	int k = 0;
	while (front != NULL) {
		temp->Push_back(new Element_deque(front->data));
		Pop_front();
		k++;
	}
	while (temp->front != NULL) {
		Push_back(new Element_deque(temp->front->data));
		temp->Pop_front();
	}
	delete temp;
	return k;
}

void Deque::FileIn() {
	ifstream in("in_deque.txt");
	char a;
	for (int i = 0; i < 5; i++) {
		Element_deque* temp = new Element_deque;
		in >> a;
		temp->data = a;
		Push_back(temp);
	}
	in.close();
}

void Deque::Out() {
	ofstream out("out_deque.txt");
	int k = Count();
	cout << "Дек:\n";
	out << "Дек:\n";
	if (k == 0) {
		cout << "Дек пустой...\n";
		out << "Дек пустой...\n";
		out.close();
		return;
	}
	for (int i = 0; i < k; i++) {
		cout << setw(3) << front->data;
		out << setw(3) << front->data;
		Push_back(new Element_deque(front->data));
		Pop_front();
	}
	cout << "\n<---------------\n";
	cout << "front---------back\n";
	cout << endl;
	out << "\n<---------------\n";
	out << "front---------back\n";
	out << endl;
	out.close();
}

char Deque::GetSix() {
	int k = Count();
	if (k < 6) {
		cout << "В деке меньше 6 элементов.\n";
		return ' ';
	}
	Deque* temp = new Deque;
	char c;
	if (k > 12) {
		for (int i = 0; i < 5; i++) {
			temp->Push_back(new Element_deque(front->data));
			Pop_front();
		}
		c = front->data;
		for (int i = 0; i < 5; i++) {
			Push_front(new Element_deque(temp->back->data));
			temp->Pop_back();
		}
	}
	else {
		for (int i = 0; i < k - 6; i++) {
			temp->Push_front(new Element_deque(back->data));
			Pop_back();
		}
		c = back->data;
		for (int i = 0; i < k - 6; i++) {
			Push_back(new Element_deque(front->data));
			temp->Pop_front();
		}
	}
	delete temp;
	return c;
}

void Deque::Clear() {
	while (front != NULL) {
		Pop_front();
	}
}