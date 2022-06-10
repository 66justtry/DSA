#include "Header.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Stack::Stack() {
	top = NULL;
}

void Stack::FileIn() {
	ifstream in("in_queue.txt");
	char a;
	for (int i = 0; i < 5; i++) {
		Element_stack* temp = new Element_stack;
		in >> a;
		temp->data = a;
		Push(temp);
	}
	in.close();
}

void Stack::Out() {
	ofstream out("out_stack.txt");
	cout << "����:\n";
	out << "����:\n";
	if (top == NULL) {
		cout << "���� ������...\n";
		out << "���� ������...\n";
		out.close();
		return;
	}
	Stack* temp = new Stack;
	while (this->top != NULL) {
		temp->Push(new Element_stack(this->top->data));
		cout << setw(5) << top->data << endl;
		out << setw(5) << top->data << endl;
		Pop();
	}
	while (temp->top != NULL) {
		Push(new Element_stack(temp->top->data));
		temp->Pop();
	}
	out.close();
	delete temp;
}

int Stack::Count() {
	Stack* temp = new Stack;
	int k = 0;
	while (this->top != NULL) {
		temp->Push(new Element_stack(this->top->data));
		Pop();
		k++;
	}
	while (temp->top != NULL) {
		Push(new Element_stack(temp->top->data));
		temp->Pop();
	}
	delete temp;
	return k;
}

void Stack::Push(Element_stack* temp) {
	if (top != NULL) {
		temp->next = top;
	}
	top = temp;
}

void Stack::Pop() {
	if (top != NULL) {
		Element_stack* temp = top;
		top = top->next;
		delete temp;
	}
}

void Stack::Clear() {
	while (top != NULL)
		Pop();
}

Stack* Stack::SwapFirstLast() {
	Stack* new_stack = new Stack; //����� ����, ��� ����� ���������
	Stack* temp = new Stack; //��������� ����, ��� �������� �������� ����� ������ � ���������

	new_stack->Push(new Element_stack(this->top->data)); //������� ������� ����� � ����� ����
	Pop(); //������� ������� �������
	while (this->top->next != NULL) { //�������� �������� �� ��������� ����
		temp->Push(new Element_stack(this->top->data));
		Pop();
	}
	while (temp->top != NULL) { //���������� ��� �������� � ����� ����, ����� ����������
		new_stack->Push(new Element_stack(temp->top->data));
		temp->Pop();
	}
	new_stack->Push(new Element_stack(this->top->data)); //�������� ��������� �������
	Pop();
	delete this;
	delete temp;
	return new_stack;
}

Stack* Stack::Expand() {
	Stack* new_stack = new Stack;
	while (this->top != NULL) {
		new_stack->Push(new Element_stack(this->top->data));
		Pop();
	}
	delete this;
	return new_stack;
}

void Stack::DeleteSecond() {
	Stack* temp = new Stack;
	while (this->top != NULL) {
		temp->Push(new Element_stack(this->top->data));
		Pop();
		Pop();
	}
	while (temp->top != NULL) {
		Push(new Element_stack(temp->top->data));
		temp->Pop();
	}
	delete temp;
}

void Stack::AddMiddle() {
	Stack* temp = new Stack;
	double k = Count();
	k /= 2;
	k = round(k);
	for (int i = 0; i < k; i++) {
		temp->Push(new Element_stack(this->top->data));
		Pop();
	}
	Push(new Element_stack('*'));
	while (temp->top != NULL) {
		Push(new Element_stack(temp->top->data));
		temp->Pop();
	}
	delete temp;
}

void Stack::FindMax(int& pos, char& symbol) {
	Stack* temp = new Stack;
	pos = 0;
	symbol = this->top->data;
	temp->Push(new Element_stack(this->top->data));
	Pop();
	int k = this->Count();
	for (int i = 1; i < k + 1; i++) {
		if (this->top->data > symbol) {
			symbol = this->top->data;
			pos = i;
		}
		temp->Push(new Element_stack(this->top->data));
		Pop();
	}
	while (temp->top != NULL) {
		Push(new Element_stack(temp->top->data));
		temp->Pop();
	}
	delete temp;
}

void Stack::FindMin(int& pos, char& symbol) {
	Stack* temp = new Stack;
	pos = 0;
	symbol = this->top->data;
	temp->Push(new Element_stack(this->top->data));
	Pop();
	int k = this->Count();
	for (int i = 1; i < k + 1; i++) {
		if (this->top->data < symbol) {
			symbol = this->top->data;
			pos = i;
		}
		temp->Push(new Element_stack(this->top->data));
		Pop();
	}
	while (temp->top != NULL) {
		Push(new Element_stack(temp->top->data));
		temp->Pop();
	}
	delete temp;
}

void Stack::AddZeroMax() {
	Stack* temp = new Stack;
	int pos;
	char symbol;
	FindMax(pos, symbol);
	for (int i = 0; i < pos + 1; i++) {
		temp->Push(new Element_stack(this->top->data));
		Pop();
	}
	Push(new Element_stack('0'));
	while (temp->top != NULL) {
		Push(new Element_stack(temp->top->data));
		temp->Pop();
	}
	delete temp;
}

void Stack::DeleteMin() {
	Stack* temp = new Stack;
	int pos;
	char symbol;
	FindMin(pos, symbol);
	for (int i = 0; i < pos; i++) {
		temp->Push(new Element_stack(this->top->data));
		Pop();
	}
	Pop();
	while (temp->top != NULL) {
		Push(new Element_stack(temp->top->data));
		temp->Pop();
	}
	delete temp;
}

void Stack::FirstLeft() {
	while (top->next != NULL) {
		Pop();
	}
}

void Stack::LastLeft() {
	Element_stack* temp = new Element_stack(top->data);
	while (top != NULL) {
		Pop();
	}
	Push(temp);
}