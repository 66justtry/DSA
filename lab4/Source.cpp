#include "Header.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int main() {
	setlocale(0, "Ru");
	srand(time(NULL));
	
	int n = 10;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << "\n\n";

	Timer t;
	
	//InsertionSort(arr, n);
	//RadixSort(arr, n, 4);

	HeapSort(arr, n);
	
	//cout << "Time elapsed: " << t.elapsed() << '\n';

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n\n";

	



	delete[] arr;
	system("pause");
	return 0;
}