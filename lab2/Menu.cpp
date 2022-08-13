#include "Header.h"
#include <iostream>

void menu(Stack* stack) {
	stack->Out();
	cout << endl;
	int ch;
	cout << "1 - ������� ����� ����\n";
	cout << "2 - �������� �������\n";
	cout << "3 - ������� �������\n";
	cout << "4 - ���������� ���������\n";
	cout << "5 - �������� ������� ������ � ��������� �������\n";
	cout << "6 - ����������� ����\n";
	cout << "7 - ������� ������ ������ �������\n";
	cout << "8 - �������� � �������� �����\n";
	cout << "9 - �������� ����� ������������� ��������\n";
	cout << "10 - ������� ����������� �������\n";
	cout << "11 - ������� ��� �������� ����� �������\n";
	cout << "12 - ������� ��� �������� ����� ����������\n";
	cout << "13 - �����\n";

	cin >> ch;
	if (ch == 1) {
		cout << "1 - �� �����\n";
		cout << "2 - � ����������\n";
		int x;
		cin >> x;
		stack->Clear();
		if (x == 1) {
			stack->FileIn();
		}
		else if (x == 2) {
			cout << "���������� ���������: ";
			cin >> x;
			for (int i = 0; i < x; i++) {
				char temp;
				cin >> temp;
				stack->Push(new Element_stack(temp));
			}
		}
	}
	else if (ch == 2) {
		cout << "����� �������: ";
		char temp;
		cin >> temp;
		stack->Push(new Element_stack(temp));
	}
	else if (ch == 3) {
		if (stack->Count() == 0)
			cout << "������� ������.\n";
		else {
			stack->Pop();
			cout << "������� ������.\n";
		}
	}
	else if (ch == 4) {
		cout << "���������� ��������� � �����: " << stack->Count() << endl;
	}
	else if (ch == 5) {
		if (stack->Count() > 0)
			stack = stack->SwapFirstLast();
		else
			cout << "���� ������.\n";
	}
	else if (ch == 6) {
		if (stack->Count() > 0)
			stack = stack->Expand();
		else
			cout << "���� ������.\n";
	}
	else if (ch == 7) {
		if (stack->Count() > 0)
			stack->DeleteSecond();
		else
			cout << "���� ������.\n";
	}
	else if (ch == 8) {
		if (stack->Count() > 0)
			stack->AddMiddle();
		else
			cout << "���� ������.\n";
	}
	else if (ch == 9) {
		if (stack->Count() > 0)
			stack->AddZeroMax();
		else
			cout << "���� ������.\n";
	}
	else if (ch == 10) {
		if (stack->Count() > 0) {
			stack->DeleteMin();
		}
		else
			cout << "���� ������.\n";
	}
	else if (ch == 11) {
		if (stack->Count() > 0)
			stack->FirstLeft();
		else
			cout << "���� ������.\n";
	}
	else if (ch == 12) {
		if (stack->Count() > 0)
			stack->LastLeft();
		else
			cout << "���� ������.\n";
	}
	else if (ch == 13) {
		stack->Clear();
		return;
	}
	cout << "\n\n";
	system("pause");
	menu(stack);
}

void menu(Queue* queue) {
	queue->Out();
	cout << endl;
	int ch;
	cout << "1 - ������� ����� �������\n";
	cout << "2 - �������� �������\n";
	cout << "3 - ������� �������\n";
	cout << "4 - ���������� ���������\n";
	cout << "5 - ������� �������������� ���������\n";
	cout << "6 - ����� ����������� � ������������ �������\n";
	cout << "7 - ������� ������� ����� �����������\n";
	cout << "8 - �����\n";
	cin >> ch;
	if (ch == 1) {
		cout << "1 - �� �����\n";
		cout << "2 - � ����������\n";
		int x;
		cin >> x;
		queue->Clear();
		if (x == 1)
			queue->FileIn();
		else if (x == 2) {
			cout << "���������� ���������: ";
			cin >> x;
			for (int i = 0; i < x; i++) {
				char temp;
				cin >> temp;
				queue->Push(new Element_queue(temp));
			}
		}
	}
	else if (ch == 2) {
		cout << "����� �������: ";
		char temp;
		cin >> temp;
		queue->Push(new Element_queue(temp));
	}
	else if (ch == 3) {
		if (queue->Count() == 0)
			cout << "������� ������.\n";
		else {
			queue->Pop();
			cout << "������� ������.\n";
		}
	}
	else if (ch == 4) {
		cout << "���������� ��������� � �������: " << queue->Count() << endl;
	}
	else if (ch == 5) {
		if (queue->Count() == 0)
			cout << "������� ������.\n";
		else
			cout << "������� �������������� ���������: " << queue->Middle() << endl;
	}
	else if (ch == 6) {
		if (queue->Count() != 0) {
			int pos;
			char symbol;
			queue->FindMin(pos, symbol);
			cout << "����������� �������: " << symbol << " �������: " << pos + 1 << endl;
			queue->FindMax(pos, symbol);
			cout << "������������ �������: " << symbol << " �������: " << pos + 1 << endl;
		}
		else
			cout << "������� ������.\n";
	}
	else if (ch == 7) {
		if (queue->Count() == 0)
			cout << "������� ������.\n";
		else {
			cout << "������� ����� �����������: ";
			queue->NextMin();
		}
	}
	else if (ch == 8) {
		queue->Clear();
		return;
	}

	cout << "\n\n";
	system("pause");
	menu(queue);
}

void menu(Deque* deque) {
	deque->Out();
	cout << endl;
	int ch;
	cout << "1 - ������� ����� ���\n";
	cout << "2 - �������� � ������\n";
	cout << "3 - �������� � �����\n";
	cout << "4 - ������� �� ������\n";
	cout << "5 - ������� �� �����\n";
	cout << "6 - ���������� ���������\n";
	cout << "7 - ��������� 6 �������\n";
	cout << "8 - ��������� ��������� �������\n";
	cout << "9 - ��������� �� �������\n";
	cout << "10 - �����\n";
	cin >> ch;
	if (ch == 1) {
		cout << "1 - �� �����\n";
		cout << "2 - � ����������\n";
		int x;
		cin >> x;
		deque->Clear();
		if (x == 1)
			deque->FileIn();
		else if (x == 2) {
			cout << "���������� ���������: ";
			cin >> x;
			for (int i = 0; i < x; i++) {
				char temp;
				cin >> temp;
				deque->Push_back(new Element_deque(temp));
			}
		}
	}
	else if (ch == 2) {
		cout << "����� �������: ";
		char temp;
		cin >> temp;
		deque->Push_front(new Element_deque(temp));
	}
	else if (ch == 3) {
		cout << "����� �������: ";
		char temp;
		cin >> temp;
		deque->Push_back(new Element_deque(temp));
	}
	else if (ch == 4) {
		if (deque->Count() == 0)
			cout << "��� ������.\n";
		else {
			deque->Pop_front();
			cout << "������� ������.\n";
		}
	}
	else if (ch == 5) {
		if (deque->Count() == 0)
			cout << "��� ������.\n";
		else {
			deque->Pop_back();
			cout << "������� ������.\n";
		}
	}
	else if (ch == 6) {
		cout << "���������� ��������� � ����: " << deque->Count() << endl;
	}
	else if (ch == 7) {
		char c = deque->GetSix();
		cout << "������ �������: " << c << endl;
	}
	else if (ch == 8) {
		if (deque->Count() == 0) {
			cout << "��� ������.\n";
		}
		else {
			cout << "��������� �������: " << deque->back->data << endl;
		}
	}
	else if (ch == 9) {
		if (deque->Count() == 0)
			cout << "��� ������.\n";
		else
			cout << "��� �� ������.\n";
	}
	else if (ch == 10) {
		deque->Clear();
		return;
	}
	cout << "\n\n";
	system("pause");
	menu(deque);
}