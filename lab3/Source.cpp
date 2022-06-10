#include "Header.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	setlocale(0, "Ru");
	system("color F0");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, 224);

	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	


	BinaryTree<string, int, int>* tree = new BinaryTree<string, int, int>;

	tree->Add(new Node<string, int, int>("l", 2003, 12), tree->root);
	tree->Add(new Node<string, int, int>("g", 1993, 30), tree->root);
	tree->Add(new Node<string, int, int>("b", 1991, 20), tree->root);
	tree->Add(new Node<string, int, int>("x", 1888, 20), tree->root);
	tree->Add(new Node<string, int, int>("w", 1000, 2), tree->root);
	tree->Add(new Node<string, int, int>("j", 2000, 30), tree->root);
	


	tree->Show(tree->root);
	cout << "\n\n\n\n\n";


	


	/*Node<string, int, int>* node = tree->root;
	Node<string, int, int>* parent = NULL;


	tree->FindNode(&node, &parent, "g");
	tree->DeleteNode(node, parent);


	system("pause");
	system("cls");

	system("color F0");
	SetConsoleTextAttribute(hStdOut, 224);
	tree->Show(tree->root);*/




	cout << "\n\n\n\n\n";
	delete tree;

	COORD coord = { (SHORT)0, (SHORT)30 };
	SetConsoleCursorPosition(hOut, coord);

	system("pause");
	return 0;
}