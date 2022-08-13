#include "Header.h"
#include <iostream>

void menu(Stack* stack) {
	stack->Out();
	cout << endl;
	int ch;
	cout << "1 - Создать новый стек\n";
	cout << "2 - Добавить элемент\n";
	cout << "3 - Удалить элемент\n";
	cout << "4 - Количество элементов\n";
	cout << "5 - Поменять местами первый и последний элемент\n";
	cout << "6 - Перевернуть стек\n";
	cout << "7 - Удалить каждый второй элемент\n";
	cout << "8 - Добавить в середину стека\n";
	cout << "9 - Вставить после максимального элемента\n";
	cout << "10 - Удалить минимальный элемент\n";
	cout << "11 - Удалить все элементы кроме первого\n";
	cout << "12 - Удалить все элементы кроме последнего\n";
	cout << "13 - Выход\n";

	cin >> ch;
	if (ch == 1) {
		cout << "1 - Из файла\n";
		cout << "2 - С клавиатуры\n";
		int x;
		cin >> x;
		stack->Clear();
		if (x == 1) {
			stack->FileIn();
		}
		else if (x == 2) {
			cout << "Количество элементов: ";
			cin >> x;
			for (int i = 0; i < x; i++) {
				char temp;
				cin >> temp;
				stack->Push(new Element_stack(temp));
			}
		}
	}
	else if (ch == 2) {
		cout << "Новый элемент: ";
		char temp;
		cin >> temp;
		stack->Push(new Element_stack(temp));
	}
	else if (ch == 3) {
		if (stack->Count() == 0)
			cout << "Очередь пустая.\n";
		else {
			stack->Pop();
			cout << "Элемент удален.\n";
		}
	}
	else if (ch == 4) {
		cout << "Количество элементов в стеке: " << stack->Count() << endl;
	}
	else if (ch == 5) {
		if (stack->Count() > 0)
			stack = stack->SwapFirstLast();
		else
			cout << "Стек пустой.\n";
	}
	else if (ch == 6) {
		if (stack->Count() > 0)
			stack = stack->Expand();
		else
			cout << "Стек пустой.\n";
	}
	else if (ch == 7) {
		if (stack->Count() > 0)
			stack->DeleteSecond();
		else
			cout << "Стек пустой.\n";
	}
	else if (ch == 8) {
		if (stack->Count() > 0)
			stack->AddMiddle();
		else
			cout << "Стек пустой.\n";
	}
	else if (ch == 9) {
		if (stack->Count() > 0)
			stack->AddZeroMax();
		else
			cout << "Стек пустой.\n";
	}
	else if (ch == 10) {
		if (stack->Count() > 0) {
			stack->DeleteMin();
		}
		else
			cout << "Стек пустой.\n";
	}
	else if (ch == 11) {
		if (stack->Count() > 0)
			stack->FirstLeft();
		else
			cout << "Стек пустой.\n";
	}
	else if (ch == 12) {
		if (stack->Count() > 0)
			stack->LastLeft();
		else
			cout << "Стек пустой.\n";
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
	cout << "1 - Создать новую очередь\n";
	cout << "2 - Добавить элемент\n";
	cout << "3 - Удалить элемент\n";
	cout << "4 - Количество элементов\n";
	cout << "5 - Среднее арифметическое элементов\n";
	cout << "6 - Найти минимальный и максимальный элемент\n";
	cout << "7 - Вывести элемент перед минимальным\n";
	cout << "8 - Выход\n";
	cin >> ch;
	if (ch == 1) {
		cout << "1 - Из файла\n";
		cout << "2 - С клавиатуры\n";
		int x;
		cin >> x;
		queue->Clear();
		if (x == 1)
			queue->FileIn();
		else if (x == 2) {
			cout << "Количество элементов: ";
			cin >> x;
			for (int i = 0; i < x; i++) {
				char temp;
				cin >> temp;
				queue->Push(new Element_queue(temp));
			}
		}
	}
	else if (ch == 2) {
		cout << "Новый элемент: ";
		char temp;
		cin >> temp;
		queue->Push(new Element_queue(temp));
	}
	else if (ch == 3) {
		if (queue->Count() == 0)
			cout << "Очередь пустая.\n";
		else {
			queue->Pop();
			cout << "Элемент удален.\n";
		}
	}
	else if (ch == 4) {
		cout << "Количество элементов в очереди: " << queue->Count() << endl;
	}
	else if (ch == 5) {
		if (queue->Count() == 0)
			cout << "Очередь пустая.\n";
		else
			cout << "Среднее арифметическое элементов: " << queue->Middle() << endl;
	}
	else if (ch == 6) {
		if (queue->Count() != 0) {
			int pos;
			char symbol;
			queue->FindMin(pos, symbol);
			cout << "Минимальный элемент: " << symbol << " позиция: " << pos + 1 << endl;
			queue->FindMax(pos, symbol);
			cout << "Максимальный элемент: " << symbol << " позиция: " << pos + 1 << endl;
		}
		else
			cout << "Очередь пустая.\n";
	}
	else if (ch == 7) {
		if (queue->Count() == 0)
			cout << "Очередь пустая.\n";
		else {
			cout << "Элемент перед минимальным: ";
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
	cout << "1 - Создать новый дек\n";
	cout << "2 - Добавить в начало\n";
	cout << "3 - Добавить в конец\n";
	cout << "4 - Удалить из начала\n";
	cout << "5 - Удалить из конца\n";
	cout << "6 - Количество элементов\n";
	cout << "7 - Прочитать 6 элемент\n";
	cout << "8 - Прочитать последний элемент\n";
	cout << "9 - Проверить на пустоту\n";
	cout << "10 - Выход\n";
	cin >> ch;
	if (ch == 1) {
		cout << "1 - Из файла\n";
		cout << "2 - С клавиатуры\n";
		int x;
		cin >> x;
		deque->Clear();
		if (x == 1)
			deque->FileIn();
		else if (x == 2) {
			cout << "Количество элементов: ";
			cin >> x;
			for (int i = 0; i < x; i++) {
				char temp;
				cin >> temp;
				deque->Push_back(new Element_deque(temp));
			}
		}
	}
	else if (ch == 2) {
		cout << "Новый элемент: ";
		char temp;
		cin >> temp;
		deque->Push_front(new Element_deque(temp));
	}
	else if (ch == 3) {
		cout << "Новый элемент: ";
		char temp;
		cin >> temp;
		deque->Push_back(new Element_deque(temp));
	}
	else if (ch == 4) {
		if (deque->Count() == 0)
			cout << "Дек пустой.\n";
		else {
			deque->Pop_front();
			cout << "Элемент удален.\n";
		}
	}
	else if (ch == 5) {
		if (deque->Count() == 0)
			cout << "Дек пустой.\n";
		else {
			deque->Pop_back();
			cout << "Элемент удален.\n";
		}
	}
	else if (ch == 6) {
		cout << "Количество элементов в деке: " << deque->Count() << endl;
	}
	else if (ch == 7) {
		char c = deque->GetSix();
		cout << "Шестой элемент: " << c << endl;
	}
	else if (ch == 8) {
		if (deque->Count() == 0) {
			cout << "Дек пустой.\n";
		}
		else {
			cout << "Последний элемент: " << deque->back->data << endl;
		}
	}
	else if (ch == 9) {
		if (deque->Count() == 0)
			cout << "Дек пустой.\n";
		else
			cout << "Дек не пустой.\n";
	}
	else if (ch == 10) {
		deque->Clear();
		return;
	}
	cout << "\n\n";
	system("pause");
	menu(deque);
}