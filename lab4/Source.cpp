#include "Header.h"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
	setlocale(0, "Ru");
	srand(time(NULL));

	int n = 30;
	int* arr = new int[n];
	cout << "\nInsertion sort\n";
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << "\n";
	

	Timer t;
	
	InsertionSort(arr, n);
	cout << "Time: " << t.elapsed() << '\n';
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << "\n\n";

	cout << "-------------------------\n";
	cout << "Radix sort\n";
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << "\n";

	t.reset();
	RadixSort(arr, n, 2);
	cout << "Time: " << t.elapsed() << '\n';
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << "\n\n";

	cout << "-------------------------\n";
	cout << "Heap sort\n";
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << "\n";

	t.reset();
	HeapSort(arr, n);
	cout << "Time: " << t.elapsed() << '\n';
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";


	/*for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n\n";*/

	//Test();

	delete[] arr;
	system("pause");
	return 0;
}