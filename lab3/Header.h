#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <typeinfo>
using namespace std;



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
	if (data_num == 1) {
		value += leaf->data1;
		n++;
	}
	else if (data_num == 2) {
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
		cout << node->key << endl;
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
	cout << node->key << endl;
}


template <class T1, class T2, class T3>
void BinaryTree<T1, T2, T3>::SymmetricOrder(Node<T1, T2, T3>* node) {
	if (node != NULL) {
		SymmetricOrder(node->left);
		cout << node->key << endl;
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
		if (parent->left->key == node->key)
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
		if (parent->left->key == node->key)
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
			if (parent->left->key == node->key)
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
		if (parent->left->key == node->key)
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
