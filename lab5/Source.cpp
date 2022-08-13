#include "Header.h"
#include "D:\\111\\хпи\\2 курс\\алгоритмы\\lab4\\Header.h"
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int main() {
	setlocale(0, "Ru");
	srand(time(NULL));

	int n = 25;
	int* arr = new int[n];

	/*for (int i = 0; i < n; i++)
		arr[i] = rand() % 200;*/




	//for (int i = 0; i < n; i++) {
	//	arr[i] = rand() % 50;
	//	//cout << arr[i] << " ";
	//}

	//ofstream out("data1.txt");
	//for (int i = 0; i < n; i++) {
	//	out << arr[i] << " ";
	//}
	//out.close();


	ifstream in1("data1.txt");
	for (int i = 0; i < n; i++)
		in1 >> arr[i];
	in1.close();

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	int x = 12;
	cout << "\n\n";
	cout << "Поиск элемента: " << x << "\n\n";
	int k = 0;
	int pos;
	cout << "Линейный поиск:\n";
	pos = LinearSearch(arr, n, x, k);
	cout << "Номер элемента: " << pos << ", Значение: " << arr[pos] << endl;
	cout << "Количество операций: " << k << endl;
	cout << "-----------------------------\n";
	cout << "Поиск с барьером:\n";
	pos = LinearSearchBarrier(arr, n, x, k);
	cout << "Номер элемента: " << pos << ", Значение: " << arr[pos] << endl;
	cout << "Количество операций: " << k << endl;
	cout << "-----------------------------\n";
	InsertionSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "Бинарный поиск:\n";
	pos = BinarySearch(arr, n, x, k);
	cout << "Номер элемента: " << pos << ", Значение: " << arr[pos] << endl;
	cout << "Количество операций: " << k << endl;
	cout << "-----------------------------\n";

	cout << "\n\n\n";
	system("pause");
	cout << "\n\n\n";


	

	ifstream in2("data2.txt");
	char str[50];
	char c;
	for (int i = 0; i < 50; i++) {
		in2 >> c;
		str[i] = c;
	}
	in2.close();
	cout << "Входная строка:\n";
	for (int i = 0; i < 50; i++)
		cout << str[i];
	cout << "\n\n";
	char substr[]{ "wof" }; //wof

	string s1 = str;
	string s2 = substr;

	cout << "Подстрока для поиска: " << substr << "\n\n";
	cout << "Прямой поиск:\n";
	pos = SimpleSearch(str, substr, k);
	cout << "Позиция: " << pos << endl;
	cout << "Количество операций: " << k << endl;
	cout << "------------------------\n";
	cout << "Алгоритм Кнута-Морриса-Пратта:\n";
	pos = KMPSearch(str, substr, k);
	cout << "Позиция: " << pos << endl;
	cout << "Количество операций: " << k << endl;
	cout << "------------------------\n";
	cout << "Алгоритм Бойера-Мура:\n";
	pos = BMSearch(str, substr, k);
	cout << "Позиция: " << pos << endl;
	cout << "Количество операций: " << k << endl;
	cout << "------------------------\n";
	cout << "Алгоритм Рабина-Карпа:\n";
	rabin_karp(s1, s2, 97, k);
	cout << "Количество операций: " << k << endl;
	cout << "------------------------\n";





	/*delete[] text;
	delete[] str;*/

	delete[] arr;
	system("pause");
	return 0;
}