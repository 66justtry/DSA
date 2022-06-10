#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Data {
public:
	double v;
	Data() {
		v = 0;
	}
	Data(double data) {
		v = data;
	}
};

class Node {
public:
	Data* data;
	Node* next;
	Node* prev;
	friend class List;
};

class List {
public:
	Node* head;
	Node* tail;
	int count;
	List() {
		head = NULL;
		tail = NULL;
		count = 0;
	}
	void AddEnd(Data*);
	void AddBegin(Data*);
	void Clear();
	void Delete(int);
	void Swap(int, int);
	List* AddList(List*, List*);
	void Show();
};

class List_circular {
public:
	Node* head;
	Node* tail;
	int count;
	List_circular() {
		head = NULL;
		tail = NULL;
		count = 0;
	}
	void AddEnd(Data*);
	void AddBegin(Data*);
	void Clear();
	void Delete(int);
	void Swap(int, int);
	List_circular* AddList(List_circular*, List_circular*);
	void Show();
};

void menu(List*);

void menu(List_circular*);