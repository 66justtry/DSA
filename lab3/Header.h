#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <typeinfo>
using namespace std;

bool str = false;


template <class T1, class T2, class T3>
class Node {
public:
	T1 key; //default: название журнала <string>
	T2 data1; //default: год выпуска
	T3 data2; //default: кол-во номеров
	Node* left;
	Node* right;
	Node() {
		left = NULL;
		right = NULL;
	}
	Node(T1 a, T2 b, T3 c) {
		key = a;
		data1 = b;
		data2 = c;
		left = NULL;
		right = NULL;
	}
	void Out1() {
		cout << setw(10) << key << endl;
	}
	void Out2() {
		cout << setw(10) << data1 << endl;
	}
	void Out3() {
		cout << setw(10) << data2 << endl;
	}
	void ToString() {
		if (this == NULL) {
			cout << "NULL\n";
			return;
		}
		cout << setw(10) << key << endl;
		cout << setw(10) << data1 << endl;
		cout << setw(10) << data2 << endl;
	}
};


template <class T1, class T2, class T3>
class BinaryTree {
public:
	Node<T1, T2, T3>* root;
	BinaryTree();
	~BinaryTree() {
		Clear(this->root);
	}
	void FileIn();
	void Add(Node<T1, T2, T3>*, Node<T1, T2, T3>*);
	void Show(Node<T1, T2, T3>*, int l = 60, int level = 5);
	void Clear(Node<T1, T2, T3>*);
	void GetAverage(Node<T1, T2, T3>*, int, double& = 0, int& = 0);
	void PreOrder(Node<T1, T2, T3>*);
	void PostOrder(Node<T1, T2, T3>*);
	void SymmetricOrder(Node<T1, T2, T3>*);
	void DeleteSubtreeLeft(Node<T1, T2, T3>*);
	void DeleteSubtreeRight(Node<T1, T2, T3>*);
	void FindNode(Node<T1, T2, T3>**, Node<T1, T2, T3>**, T1);
	void DeleteNode(Node<T1, T2, T3>*, Node<T1, T2, T3>*);
	BinaryTree<T2, T1, T3>* ChangeKey();
	void CopyNodes(BinaryTree<T2, T1, T3>*, Node<T1, T2, T3>*);
};

void WriteDots(int n, int posx, int posy);


//void SetCursorPosition1(int x, int y)
//{
//	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	std::cout.flush();
//	COORD coord = { (SHORT)x, (SHORT)y };
//	SetConsoleCursorPosition(hOut, coord);
//}

template<class T1, class T2, class T3>
BinaryTree<T1, T2, T3>::BinaryTree() {
	root = NULL;
}

template<class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::FileIn() {
	ifstream in("in.txt");
	T1 key;
	T2 data1;
	T3 data2;
	for (int i = 0; i < 5; i++) {
		in >> key;
		in >> data1;
		in >> data2;
		Add(new Node<T1, T2, T3>(key, data1, data2), this->root);
	}
	in.close();
}


template<class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::Add(Node<T1, T2, T3>* node, Node<T1, T2, T3>* leaf) {

	if (leaf == NULL) {
		root = node;
		return;
	}

	if (node->key < leaf->key)
	{
		if (leaf->left != NULL)
			Add(node, leaf->left);
		else
			leaf->left = node;
	}
	else if (node->key >= leaf->key)
	{
		if (leaf->right != NULL)
			Add(node, leaf->right);
		else
			leaf->right = node;
	}

}




template<class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::Show(Node<T1, T2, T3>* leaf, int l, int level) {
	if (root == NULL) {
		cout << "Бинарное дерево пустое...\n";
		return;
	}

	//SetCursorPosition(l, level);

	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)l, (SHORT)level };
	SetConsoleCursorPosition(hOut, coord);


	leaf->Out1();
	coord = { (SHORT)l, (SHORT)(level + 1) };
	SetConsoleCursorPosition(hOut, coord);
	leaf->Out2();
	coord = { (SHORT)l, (SHORT)(level + 2) };
	SetConsoleCursorPosition(hOut, coord);
	leaf->Out3();


	if (leaf->left != NULL) {
		WriteDots(21 - level * 1.2, l - 21 + level * 1.2, level + 2);
		COORD coord = { (SHORT)(l - 21 + level * 1.2), (SHORT)(level + 3) };
		SetConsoleCursorPosition(hOut, coord);
		cout << ".";
		coord = { (SHORT)(l - 21 + level * 1.2), (SHORT)(level + 4) };
		SetConsoleCursorPosition(hOut, coord);
		cout << ".";
		Show(leaf->left, l - 30 + level * 1.2, level + 5);
	}
	if (leaf->right != NULL) {
		WriteDots(21 - level * 1.2, l + 10, level + 2);
		COORD coord = { (SHORT)(l + 30 - level * 1.2), (SHORT)(level + 3) };
		SetConsoleCursorPosition(hOut, coord);
		cout << ".";
		coord = { (SHORT)(l + 30 - level * 1.2), (SHORT)(level + 4) };
		SetConsoleCursorPosition(hOut, coord);
		cout << ".";
		Show(leaf->right, l + 30 - level * 1.2, level + 5);
	}

}


template<class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::Clear(Node<T1, T2, T3>* leaf) {
	if (root == NULL)
		return;
	if (leaf->left != NULL)
		Clear(leaf->left);
	if (leaf->right != NULL)
		Clear(leaf->right);
	delete leaf;
}

template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::GetAverage(Node<T1, T2, T3>* leaf, int data_num, double& value, int& n) {
	if (root == NULL) {
		cout << "Бинарное дерево пустое.\n";
		return;
	}
	if (!str) {
		/*if (data_num == 1) {
			value += leaf->data1;
			n++;
		}*/
		
	}
	if (data_num == 2) {
		value += leaf->data2;
		n++;
	}
	
	if (leaf->left != NULL)
		GetAverage(leaf->left, data_num, value, n);
	if (leaf->right != NULL)
		GetAverage(leaf->right, data_num, value, n);
}

template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::PreOrder(Node<T1, T2, T3>* node) {
	if (node != NULL) {
		cout << node->key << "  ";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}


template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::PostOrder(Node<T1, T2, T3>* node) {
	if (node == NULL)
		return;
	if (node->left != NULL)
		PostOrder(node->left);
	if (node->right != NULL)
		PostOrder(node->right);
	cout << node->key << "  ";
}


template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::SymmetricOrder(Node<T1, T2, T3>* node) {
	if (node != NULL) {
		SymmetricOrder(node->left);
		cout << node->key << "  ";
		SymmetricOrder(node->right);
	}
}

template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::DeleteSubtreeLeft(Node<T1, T2, T3>* node) {
	if (node == NULL)
		return;
	if (node->left == NULL)
		return;
	Clear(node->left);
	node->left = NULL;
}

template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::DeleteSubtreeRight(Node<T1, T2, T3>* node) {
	if (node == NULL)
		return;
	if (node->right == NULL)
		return;
	Clear(node->right);
	node->right = NULL;
}

template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::FindNode(Node<T1, T2, T3>** node, Node<T1, T2, T3>** parent, T1 val) {
	//node и parent - указатели, при вызове создать новые указатели на root и null !!!
	//в них же вернется результат - указатель на node и его root
	if (this->root == NULL) {
		cout << "Бинарное дерево пустое.\n";
		return;
	}
	if ((*node)->key > val) {
		if ((*node)->left != NULL) {
			(*parent) = (*node);
			(*node) = (*node)->left;
			FindNode(node, parent, val);
		}
		else {
			cout << "Не найдено.\n";
			(*node) = NULL;
			(*parent) = NULL;
		}
	}
	else if ((*node)->key < val) {
		if ((*node)->right != NULL) {
			(*parent) = (*node);
			(*node) = (*node)->right;
			FindNode(node, parent, val);
		}
		else {
			cout << "Не найдено.\n";
			(*node) = NULL;
			(*parent) = NULL;
		}
	}
}

template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::DeleteNode(Node<T1, T2, T3>* node, Node<T1, T2, T3>* parent) {
	if (node == NULL)
		return;

	if ((node->left == NULL) && (node->right == NULL)) {
		if (parent == NULL) {
			delete node;
			this->root = NULL;
		}
		else {
			if (parent->left->key == node->key)
				parent->left = NULL;
			else
				parent->right = NULL;
			delete node;
		}
		return;
	}

	if (node->left == NULL) {
		if (parent == NULL) {
			this->root = node->right;
			delete node;
			return;
		}
		if (parent->left != NULL && parent->left->key == node->key)
			parent->left = node->right;
		else
			parent->right = node->right;
		delete node;
		return;
	}

	if (node->right == NULL) {
		if (parent == NULL) {
			this->root = node->left;
			delete node;
			return;
		}
		if (parent->left != NULL && parent->left->key == node->key)
			parent->left = node->left;
		else
			parent->right = node->left;
		delete node;
		return;
	}


	Node<T1, T2, T3>* temp1 = node->right;

	if (temp1->left == NULL) {
		temp1->left = node->left;
		if (parent == NULL)
			this->root = temp1;
		else {
			if (parent->left != NULL && parent->left->key == node->key)
				parent->left = temp1;
			else
				parent->right = temp1;
		}
		delete node;
		return;
	}

	while (temp1->left->left != NULL)
		temp1 = temp1->left;
	temp1->left->left = node->left;
	temp1->left->right = node->right;
	if (parent == NULL)
		this->root = temp1->left;
	else {
		if (parent->left != NULL && parent->left->key == node->key)
			parent->left = temp1->left;
		else
			parent->right = temp1->left;
	}
	temp1->left = NULL;
	delete node;

}

template <class T1, class T2, class T3>
BinaryTree<T2, T1, T3>* BinaryTree<T1, T2, T3>::ChangeKey() {
	BinaryTree<T1, T2, T3>* tree = this;
	BinaryTree<T2, T1, T3>* new_tree = new BinaryTree<T2, T1, T3>();
	tree->CopyNodes(new_tree, tree->root);
	//tree->Clear(tree->root);
	return new_tree;
}

template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::CopyNodes(BinaryTree<T2, T1, T3>* new_tree, Node<T1, T2, T3>* node) {
	if (node == NULL)
		return;
	new_tree->Add(new Node<T2, T1, T3>(node->data1, node->key, node->data2), new_tree->root);

	if (node->left != NULL)
		CopyNodes(new_tree, node->left);
	if (node->right != NULL)
		CopyNodes(new_tree, node->right);
}




void WriteDots(int n, int posx, int posy) {
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { (SHORT)posx, (SHORT)posy };
	SetConsoleCursorPosition(hOut, coord);

	for (int i = 0; i < n; i++)
		cout << ".";
}

template <class T1, class T2, class T3>
void Menu(BinaryTree<T1, T2, T3>* tree) {
	system("cls");
	system("color F0");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, 224);
	tree->Show(tree->root);
	cout << "\n\n\n\n";
	int ch;
	cout << "1 - Новое дерево\n";
	cout << "2 - Добавить лист\n";
	cout << "3 - Удалить узел\n";
	cout << "4 - Удалить поддерево\n";
	cout << "5 - Найти по ключу\n";
	cout << "6 - Обход дерева\n";
	cout << "7 - Посчитать среднее арифметическое\n";
	cout << "8 - Поменять ключ\n";
	cout << "9 - Выход\n";
	cin >> ch;
	if (ch == 1) {
		tree->Clear(tree->root);
		tree->root = NULL;
		tree->FileIn();
	}
	else if (ch == 2) {
		T1 key;
		T2 data1;
		T3 data2;
		cout << "Ключ: ";
		cin >> key;
		cout << "Поле 1: ";
		cin >> data1;
		cout << "Поле 2: ";
		cin >> data2;
		tree->Add(new Node<T1, T2, T3>(key, data1, data2), tree->root);
	}
	else if (ch == 3) {
		T1 key;
		cout << "Ключ узла для удаления: ";
		cin >> key;
		Node<T1, T2, T3>* node = tree->root;
		Node<T1, T2, T3>* parent = NULL;

		tree->FindNode(&node, &parent, key);
		tree->DeleteNode(node, parent);
	}
	else if (ch == 4) {
		T1 key;
		cout << "Ключ узла для удаления: ";
		cin >> key;
		int a;
		cout << "1 - Левое поддерево\n";
		cout << "2 - Правое поддерево\n";
		cin >> a;
		Node<T1, T2, T3>* node = tree->root;
		Node<T1, T2, T3>* parent = NULL;
		tree->FindNode(&node, &parent, key);
		
		if (a == 1) {
			tree->DeleteSubtreeLeft(node);
		}
		else if (a == 2) {
			tree->DeleteSubtreeRight(node);
		}
	}
	else if (ch == 5) {
		T1 key;
		cout << "Ключ: ";
		cin >> key;
		Node<T1, T2, T3>* node = tree->root;
		Node<T1, T2, T3>* parent = NULL;
		tree->FindNode(&node, &parent, key);
		if (node != NULL) {
			node->Out1();
			node->Out2();
			node->Out3();
		}
	}
	else if (ch == 6) {
		cout << "Прямой обход:\n";
		tree->PreOrder(tree->root);
		cout << "\nОбратный обход:\n";
		tree->PostOrder(tree->root);
		cout << "\nСимметричный обход\n";
		tree->SymmetricOrder(tree->root);
	}
	else if (ch == 7) {
		int a;
		cout << "1 - По полю 1\n";
		cout << "2 - По полю 2\n";
		cin >> a;
		int n = 0;
		double value = 0;
		tree->GetAverage(tree->root, a, value, n);
		cout << "Среднее значение: " << value / n << endl;
	}
	else if (ch == 8) {
		!str;
		Menu(tree->ChangeKey());
	}
	else if (ch == 9) {
		return;
	}

	system("pause");
	Menu(tree);
}




template <class T1, class T2, class T3>
class RBNode {
public:
	T1 key; //default: название журнала <string>
	T2 data1; //default: год выпуска
	T3 data2; //default: кол-во номеров
	string color;
	RBNode* parent;
	RBNode* left;
	RBNode* right;
	RBNode() {
		parent = NULL;
		left = NULL;
		right = NULL;
		color = "red";
	}
	RBNode(T1 a, T2 b, T3 c) {
		key = a;
		data1 = b;
		data2 = c;
		parent = NULL;
		left = NULL;
		right = NULL;
		color = "red";
	}
	void Out1() {
		cout << setw(10) << key << endl;
	}
	void Out2() {
		cout << setw(10) << data1 << endl;
	}
	void Out3() {
		cout << setw(10) << data2 << endl;
	}
	void ToString() {
		if (this == NULL) {
			cout << "NULL\n";
			return;
		}
		cout << setw(10) << key << endl;
		cout << setw(10) << data1 << endl;
		cout << setw(10) << data2 << endl;
	}
};




template <class T1, class T2, class T3>
class RBTree {
public:
	RBNode<T1, T2, T3>* root;
	RBTree();
	~RBTree() {
		Clear(this->root);
	}
	void FileIn();
	void Add(RBNode<T1, T2, T3>*, RBNode<T1, T2, T3>*);
	void Show(RBNode<T1, T2, T3>*, int l = 60, int level = 5);
	void Clear(RBNode<T1, T2, T3>*);
	void GetAverage(RBNode<T1, T2, T3>*, int, double& = 0, int& = 0);
	void PreOrder(RBNode<T1, T2, T3>*);
	void PostOrder(RBNode<T1, T2, T3>*);
	void SymmetricOrder(RBNode<T1, T2, T3>*);
	void DeleteSubtreeLeft(RBNode<T1, T2, T3>*);
	void DeleteSubtreeRight(RBNode<T1, T2, T3>*);
	void FindNode(RBNode<T1, T2, T3>**, RBNode<T1, T2, T3>**, T1);
	void DeleteNode(RBNode<T1, T2, T3>*);
	RBTree<T2, T1, T3>* ChangeKey();
	void CopyNodes(RBTree<T2, T1, T3>*, RBNode<T1, T2, T3>*);
	void RotateRight(RBNode<T1, T2, T3>* node);
	void RotateLeft(RBNode<T1, T2, T3>* node);
	void Balance(RBNode<T1, T2, T3>* node, string type);
	void Case1(RBNode<T1, T2, T3>* node) {
		if (node->parent == NULL) {
			node->color = "black";
		}
		else
			Case2(node);
	}
	void Case2(RBNode<T1, T2, T3>* node) {
		if (node->parent->color == "black")
			return;
		else
			Case3(node);
	}
	void Case3(RBNode<T1, T2, T3>* node) {
		RBNode<T1, T2, T3>* u = node->parent->parent;
		if (u->left == node->parent)
			u = u->right;
		else
			u = u->left;

		if (u != NULL && u->color == "red") {
			node->parent->color = "black";
			u->color = "black";
			node->parent->parent->color = "red";
			Case1(node->parent->parent);
		}
		else {
			Case4(node);
		}
	}
	void Case4(RBNode<T1, T2, T3>* node) {
		RBNode<T1, T2, T3>* u = node->parent->parent;
		if (u->left == node->parent) { //parent - левая ветка от g
			u = u->right;
			if (node->parent->right == node) {
				RotateLeft(node);
				Case5(node->left);
			}
			else
				Case5(node);
		}
		else if (u->right == node->parent) { //parent - правая ветка от g
			u = u->left;
			if (node->parent->left == node) {
				RotateRight(node);
				Case5(node->right);
			}
			else
				Case5(node);
		}
		else
			Case5(node);
	}
	void Case5(RBNode<T1, T2, T3>* node) {
		RBNode<T1, T2, T3>* u = node->parent->parent;
		if (u->left == node->parent) { //parent - левая ветка от g
			u = u->right;
			if (node->parent->left == node) {
				RotateRight(node->parent);
				node->parent->color = "black";
				node->parent->right->color = "red";
			}
		}
		else if (u->right == node->parent) { //parent - правая ветка от g
			u = u->left;
			if (node->parent->right == node) {
				RotateLeft(node->parent);
				node->parent->color = "black";
				node->parent->left->color = "red";
			}
		}

	}
};






template<class T1, class T2, class T3>
RBTree<T1, T2, T3>::RBTree() {
	root = NULL;
}

template<class T1, class T2, class T3>
void RBTree<T1, T2, T3>::FileIn() {
	ifstream in("in.txt");
	T1 key;
	T2 data1;
	T3 data2;
	for (int i = 0; i < 5; i++) {
		in >> key;
		in >> data1;
		in >> data2;
		Add(new RBNode<T1, T2, T3>(key, data1, data2), this->root);
	}
	in.close();
}


template<class T1, class T2, class T3>
void RBTree<T1, T2, T3>::Add(RBNode<T1, T2, T3>* node, RBNode<T1, T2, T3>* leaf) {

	if (leaf == NULL) {
		root = node;
		Case1(node);
		return;
	}

	if (node->key < leaf->key)
	{
		if (leaf->left != NULL)
			Add(node, leaf->left);
		else {
			leaf->left = node;
			node->parent = leaf;
		}
	}
	else if (node->key >= leaf->key)
	{
		if (leaf->right != NULL)
			Add(node, leaf->right);
		else {
			leaf->right = node;
			node->parent = leaf;
		}
	}
	Case1(node);

}




template<class T1, class T2, class T3>
void RBTree<T1, T2, T3>::Show(RBNode<T1, T2, T3>* leaf, int l, int level) {
	if (root == NULL) {
		cout << "Дерево пустое...\n";
		return;
	}

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	

	//SetCursorPosition(l, level);

	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)l, (SHORT)level };
	SetConsoleCursorPosition(hOut, coord);

	if (leaf->color == "black")
		SetConsoleTextAttribute(hStdOut, 15);
	else
		SetConsoleTextAttribute(hStdOut, 79);
	leaf->Out1();
	coord = { (SHORT)l, (SHORT)(level + 1) };
	SetConsoleCursorPosition(hOut, coord);
	leaf->Out2();
	coord = { (SHORT)l, (SHORT)(level + 2) };
	SetConsoleCursorPosition(hOut, coord);
	leaf->Out3();


	if (leaf->left != NULL) {
		SetConsoleTextAttribute(hStdOut, 240);
		WriteDots(21 - level * 1.2, l - 21 + level * 1.2, level + 2);
		COORD coord = { (SHORT)(l - 21 + level * 1.2), (SHORT)(level + 3) };
		SetConsoleCursorPosition(hOut, coord);
		cout << ".";
		coord = { (SHORT)(l - 21 + level * 1.2), (SHORT)(level + 4) };
		SetConsoleCursorPosition(hOut, coord);
		cout << ".";
		Show(leaf->left, l - 30 + level * 1.2, level + 5);
	}
	else {
		SetConsoleTextAttribute(hStdOut, 15);
		COORD coord = { (SHORT)(l - 21 + level * 1.2), (SHORT)(level + 4) };
		SetConsoleCursorPosition(hOut, coord);
		cout << "NULL";
	}



	if (leaf->right != NULL) {
		SetConsoleTextAttribute(hStdOut, 240);
		WriteDots(21 - level * 1.2, l + 10, level + 2);
		COORD coord = { (SHORT)(l + 30 - level * 1.2), (SHORT)(level + 3) };
		SetConsoleCursorPosition(hOut, coord);
		cout << ".";
		coord = { (SHORT)(l + 30 - level * 1.2), (SHORT)(level + 4) };
		SetConsoleCursorPosition(hOut, coord);
		cout << ".";
		Show(leaf->right, l + 30 - level * 1.2, level + 5);
	}
	else {
		SetConsoleTextAttribute(hStdOut, 15);
		COORD coord = { (SHORT)(l + 27 - level * 1.2), (SHORT)(level + 4) };
		SetConsoleCursorPosition(hOut, coord);
		cout << "NULL";
	}

}


template<class T1, class T2, class T3>
void RBTree<T1, T2, T3>::Clear(RBNode<T1, T2, T3>* leaf) {
	if (root == NULL)
		return;
	if (leaf->left != NULL)
		Clear(leaf->left);
	if (leaf->right != NULL)
		Clear(leaf->right);
	delete leaf;
}

template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::GetAverage(RBNode<T1, T2, T3>* leaf, int data_num, double& value, int& n) {
	if (root == NULL) {
		cout << "Бинарное дерево пустое.\n";
		return;
	}
	if (!str) {
		/*if (data_num == 1) {
			value += leaf->data1;
			n++;
		}*/
		if (data_num == 2) {
			value += leaf->data2;
			n++;
		}
	}

	if (leaf->left != NULL)
		GetAverage(leaf->left, data_num, value, n);
	if (leaf->right != NULL)
		GetAverage(leaf->right, data_num, value, n);
}

template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::PreOrder(RBNode<T1, T2, T3>* node) {
	if (node != NULL) {
		cout << node->key << "  ";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}


template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::PostOrder(RBNode<T1, T2, T3>* node) {
	if (node == NULL)
		return;
	if (node->left != NULL)
		PostOrder(node->left);
	if (node->right != NULL)
		PostOrder(node->right);
	cout << node->key << "  ";
}


template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::SymmetricOrder(RBNode<T1, T2, T3>* node) {
	if (node != NULL) {
		SymmetricOrder(node->left);
		cout << node->key << "  ";
		SymmetricOrder(node->right);
	}
}

template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::DeleteSubtreeLeft(RBNode<T1, T2, T3>* node) {
	if (node == NULL)
		return;
	if (node->left == NULL)
		return;
	Clear(node->left);
	node->left = NULL;
}

template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::DeleteSubtreeRight(RBNode<T1, T2, T3>* node) {
	if (node == NULL)
		return;
	if (node->right == NULL)
		return;
	Clear(node->right);
	node->right = NULL;
}

template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::FindNode(RBNode<T1, T2, T3>** node, RBNode<T1, T2, T3>** parent, T1 val) {
	//node и parent - указатели, при вызове создать новые указатели на root и null !!!
	//в них же вернется результат - указатель на node и его root
	if (this->root == NULL) {
		cout << "Бинарное дерево пустое.\n";
		return;
	}
	if ((*node)->key > val) {
		if ((*node)->left != NULL) {
			(*parent) = (*node);
			(*node) = (*node)->left;
			FindNode(node, parent, val);
		}
		else {
			cout << "Не найдено.\n";
			(*node) = NULL;
			(*parent) = NULL;
		}
	}
	else if ((*node)->key < val) {
		if ((*node)->right != NULL) {
			(*parent) = (*node);
			(*node) = (*node)->right;
			FindNode(node, parent, val);
		}
		else {
			cout << "Не найдено.\n";
			(*node) = NULL;
			(*parent) = NULL;
		}
	}
}

template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::DeleteNode(RBNode<T1, T2, T3>* node) {
	if (node == NULL)
		return;


	if (node->color == "red" && node->left == NULL && node->right == NULL) { //красный узел без потомков
		if (node->parent->left == node) {
			node->parent->left = NULL;
			delete node;
		}
		else if (node->parent->right == node) {
			node->parent->right = NULL;
			delete node;
		}
	}



	else if (node->color == "red" && node->left != NULL && node->right != NULL) { //красные узел, 2 потомка
		RBNode<T1, T2, T3>* temp = node->right;
		while (temp->left != NULL) //находим похожий элемент, для замены
			temp = temp->left;
		T1 k = temp->key;
		T2 d1 = temp->data1;
		T3 d2 = temp->data2;
		temp->key = node->key;
		temp->data1 = node->data1;
		temp->data2 = node->data2;
		node->key = k;
		node->data1 = d1;
		node->data2 = d2;
		DeleteNode(temp);

	}


	else if (node->color == "black" && node->left == NULL && node->right == NULL) { //черный узел без наследников
		RBNode<string, int, int>* p = node->parent;
		if (p == NULL) {
			Clear(node);
			this->root = NULL;
			return;
		}
		if (node->parent->left == node) {
			node->parent->left = NULL;
			delete node;
			Balance(p, "left");
		}
		else if (node->parent->right == node) {
			node->parent->right = NULL;
			delete node;
			Balance(p, "right");
		}
	}

	else if (node->color == "black" && (node->left == NULL || node->right == NULL)) {

		if (node->left != NULL) {
			node->key = node->left->key;
			node->data1 = node->left->data1;
			node->data2 = node->left->data2;
			DeleteNode(node->left);
		}
		else if (node->right != NULL) {
			node->key = node->right->key;
			node->data1 = node->right->data1;
			node->data2 = node->right->data2;
			DeleteNode(node->right);
		}
	}


	else if (node->color == "black" && node->left != NULL && node->right != NULL) {
		RBNode<T1, T2, T3>* temp = node->right;
		while (temp->left != NULL) //находим похожий элемент, для замены
			temp = temp->left;
		T1 k = temp->key;
		T2 d1 = temp->data1;
		T3 d2 = temp->data2;
		temp->key = node->key;
		temp->data1 = node->data1;
		temp->data2 = node->data2;
		node->key = k;
		node->data1 = d1;
		node->data2 = d2;
		DeleteNode(temp);
	}
}

template <class T1, class T2, class T3>
RBTree<T2, T1, T3>* RBTree<T1, T2, T3>::ChangeKey() {
	RBTree<T1, T2, T3>* tree = this;
	RBTree<T2, T1, T3>* new_tree = new RBTree<T2, T1, T3>();
	tree->CopyNodes(new_tree, tree->root);
	//tree->Clear(tree->root);
	return new_tree;
}

template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::CopyNodes(RBTree<T2, T1, T3>* new_tree, RBNode<T1, T2, T3>* node) {
	if (node == NULL)
		return;
	new_tree->Add(new RBNode<T2, T1, T3>(node->data1, node->key, node->data2), new_tree->root);

	if (node->left != NULL)
		CopyNodes(new_tree, node->left);
	if (node->right != NULL)
		CopyNodes(new_tree, node->right);
}

template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::RotateRight(RBNode<T1, T2, T3>* q) {
	if (q == NULL)
		return;
	RBNode<T1, T2, T3>* p = q->parent;
	p->left = q->right;
	q->right = p;
	if (p->parent != NULL) {
		p = p->parent;
		if (p->left != NULL && p->left->key == q->right->key)
			p->left = q;
		else
			p->right = q;
		q->parent = p;
		q->right->parent = q;

		//parent 
	}
	else {
		q->parent = NULL;
		p->parent = q;
		this->root = q;
	}
}



template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::RotateLeft(RBNode<T1, T2, T3>* q) {
	if (q == NULL)
		return;
	RBNode<T1, T2, T3>* p = q->parent;
	p->right = q->left;
	q->left = p;
	if (p->parent != NULL) {
		p = p->parent;
		if (p->left != NULL && p->left->key == q->left->key)
			p->left = q;
		else
			p->right = q;
		q->parent = p;
		q->left->parent = q;

		//parent 
	}
	else {
		q->parent = NULL;
		p->parent = q;
		this->root = q;
	}
}


template <class T1, class T2, class T3>
void RBTree<T1, T2, T3>::Balance(RBNode<T1, T2, T3>* p, string type) {
	RBNode<T1, T2, T3>* b;
	if (type == "left") {
		b = p->right;
		if (b->color == "black") {
			if (b->right != NULL && b->right->color == "red") {
				b->color = p->color;
				p->color = "black";
				b->right->color = "black";
				RotateLeft(b);
				return;
			}
			else if (b->left != NULL && b->left->color == "red") {
				b->color = "red";
				b->left->color = "black";
				RotateRight(b->left);
				Balance(p, "left");
			}
			else {
				b->color = "red";
				if (p->color == "red") {
					p->color = "black";
					return;
				}
				else {
					if (p->parent != NULL && p->parent->left == p)
						Balance(p->parent, "left");
					else if (p->parent != NULL && p->parent->right == p)
						Balance(p->parent, "right");
				}
			}
		}
		else if (b->color == "red") {
			p->color = "red";
			b->color = "black";
			RotateLeft(b);
			Balance(p, "left");
		}
	}

	else if (type == "right") {
		b = p->left;
		if (b->color == "black") {
			if (b->left != NULL && b->left->color == "red") {
				b->color = p->color;
				p->color = "black";
				b->left->color = "black";
				RotateRight(b);
				return;
			}
			else if (b->right != NULL && b->right->color == "red") {
				b->color = "red";
				b->right->color = "black";
				RotateLeft(b->right);
				Balance(p, "right");
			}
			else {
				b->color = "red";
				if (p->color == "red") {
					p->color = "black";
					return;
				}
				else {
					if (p->parent != NULL && p->parent->left == p)
						Balance(p->parent, "left");
					else if (p->parent != NULL && p->parent->right == p)
						Balance(p->parent, "right");
				}
			}
		}
		else if (b->color == "red") {
			p->color = "red";
			b->color = "black";
			RotateRight(b);
			Balance(p, "right");
		}
	}

}


template <class T1, class T2, class T3>
void Menu(RBTree<T1, T2, T3>* tree) {
	system("cls");
	system("color F0");
	tree->Show(tree->root);
	cout << "\n\n\n\n\n\n\n";
	int ch;
	cout << "1 - Новое дерево\n";
	cout << "2 - Добавить лист\n";
	cout << "3 - Удалить узел\n";
	cout << "4 - Найти по ключу\n";
	cout << "5 - Выход\n";
	cin >> ch;
	if (ch == 1) {
		tree->Clear(tree->root);
		tree->root = NULL;
		tree->FileIn();
	}
	else if (ch == 2) {
		T1 key;
		T2 data1;
		T3 data2;
		cout << "Ключ: ";
		cin >> key;
		cout << "Поле 1: ";
		cin >> data1;
		cout << "Поле 2: ";
		cin >> data2;
		tree->Add(new RBNode<T1, T2, T3>(key, data1, data2), tree->root);
	}
	else if (ch == 3) {
		T1 key;
		cout << "Ключ узла для удаления: ";
		cin >> key;
		RBNode<T1, T2, T3>* node = tree->root;
		RBNode<T1, T2, T3>* parent = NULL;

		tree->FindNode(&node, &parent, key);
		tree->DeleteNode(node);
	}
	else if (ch == 4) {
		T1 key;
		cout << "Ключ: ";
		cin >> key;
		RBNode<T1, T2, T3>* node = tree->root;
		RBNode<T1, T2, T3>* parent = NULL;
		tree->FindNode(&node, &parent, key);
		if (node != NULL) {
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			if (node->color == "black")
				SetConsoleTextAttribute(hStdOut, 15);
			else
				SetConsoleTextAttribute(hStdOut, 79);
			node->Out1();
			node->Out2();
			node->Out3();
		}
	}
	else if (ch == 5) {
		return;
	}
	system("pause");
	Menu(tree);
}

