#include "Header.h"
#include "D:\\111\\���\\2 ����\\���������\\lab4\\Header.h"
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
	cout << "����� ��������: " << x << "\n\n";
	int k = 0;
	int pos;
	cout << "�������� �����:\n";
	pos = LinearSearch(arr, n, x, k);
	cout << "����� ��������: " << pos << ", ��������: " << arr[pos] << endl;
	cout << "���������� ��������: " << k << endl;
	cout << "-----------------------------\n";
	cout << "����� � ��������:\n";
	pos = LinearSearchBarrier(arr, n, x, k);
	cout << "����� ��������: " << pos << ", ��������: " << arr[pos] << endl;
	cout << "���������� ��������: " << k << endl;
	cout << "-----------------------------\n";
	InsertionSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "�������� �����:\n";
	pos = BinarySearch(arr, n, x, k);
	cout << "����� ��������: " << pos << ", ��������: " << arr[pos] << endl;
	cout << "���������� ��������: " << k << endl;
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
	cout << "������� ������:\n";
	for (int i = 0; i < 50; i++)
		cout << str[i];
	cout << "\n\n";
	char substr[]{ "wof" }; //wof

	string s1 = str;
	string s2 = substr;

	cout << "��������� ��� ������: " << substr << "\n\n";
	cout << "������ �����:\n";
	pos = SimpleSearch(str, substr, k);
	cout << "�������: " << pos << endl;
	cout << "���������� ��������: " << k << endl;
	cout << "------------------------\n";
	cout << "�������� �����-�������-������:\n";
	pos = KMPSearch(str, substr, k);
	cout << "�������: " << pos << endl;
	cout << "���������� ��������: " << k << endl;
	cout << "------------------------\n";
	cout << "�������� ������-����:\n";
	pos = BMSearch(str, substr, k);
	cout << "�������: " << pos << endl;
	cout << "���������� ��������: " << k << endl;
	cout << "------------------------\n";
	cout << "�������� ������-�����:\n";
	rabin_karp(s1, s2, 97, k);
	cout << "���������� ��������: " << k << endl;
	cout << "------------------------\n";





	/*delete[] text;
	delete[] str;*/

	delete[] arr;
	system("pause");
	return 0;
}