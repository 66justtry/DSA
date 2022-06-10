#pragma once
#include <iostream>
using namespace std;

class Element_stack {
public:
	char data;
	Element_stack* next;
	Element_stack() {
		data = ' ';
		next = NULL;
	}
	Element_stack(char a) {
		data = a;
		next = NULL;
	}
};

class Stack {
public:
	Element_stack* top;
	Stack();
	void FileIn();
	void Out();
	int Count();
	void Push(Element_stack*);
	void Pop();
	void Clear();
	Stack* SwapFirstLast();
	Stack* Expand();
	void DeleteSecond();
	void AddMiddle();
	void FindMax(int&, char&);
	void FindMin(int&, char&);
	void AddZeroMax();
	void DeleteMin();
	void FirstLeft();
	void LastLeft();
};

class Element_queue {
public:
	char data;
	Element_queue* next;
	Element_queue* prev;
	Element_queue() {
		data = ' ';
		next = NULL;
		prev = NULL;
	}
	Element_queue(char a) {
		data = a;
		next = NULL;
		prev = NULL;
	}
};

class Queue {
public:
	Element_queue* head;
	Element_queue* tail;
	Queue();
	void Push(Element_queue*);
	void Pop();
	void Clear();
	int Count();
	void FileIn();
	void Out();
	double Middle();
	void FindMax(int&, char&);
	void FindMin(int&, char&);
	void NextMin();
};

class Element_deque {
public:
	char data;
	Element_deque* next;
	Element_deque* prev;
	Element_deque() {
		data = ' ';
		next = NULL;
		prev = NULL;
	}
	Element_deque(char a) {
		data = a;
		next = NULL;
		prev = NULL;
	}
};

class Deque {
public:
	Element_deque* front;
	Element_deque* back;
	Deque();
	void Push_front(Element_deque*);
	void Push_back(Element_deque*);
	void Pop_front();
	void Pop_back();
	int Count();
	void FileIn();
	void Out();
	char GetSix();
	void Clear();
};

void menu(Stack*);

void menu(Queue*);

void menu(Deque*);