#include "Header.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(0, "Ru");
	
	
	//Stack* s = new Stack;
	//menu(s);
	//delete s;
	 
	 
	//Queue* q = new Queue;
	//menu(q);
	//delete q;

	Deque* d = new Deque;
	menu(d);
	delete d;



	system("pause");
	return 0;
}