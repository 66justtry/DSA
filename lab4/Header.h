#pragma once
#include <iostream>
#include <chrono>

using namespace std;

class Timer {
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;
public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void InsertionSort(int* arr, int n) {
	long long k = 0;
	for (int i = 1; i < n; i++) {
		k += 3;
		int temp = arr[i];
		k += 1;
		for (int j = i - 1; j >= 0; j--) {
			k += 3;
			if (arr[j] > temp) {
				k += 4;
				arr[j + 1] = arr[j];
			}
			else {
				k += 3;
				arr[j + 1] = temp;
				break;
			}
			

		}
		if (temp < arr[0]) {
			k += 3;
			arr[0] = temp;
		}
		/*for (int k = 0; k < n; k++)
			cout << arr[k] << " ";
		cout << "\n\n";*/

	}
	cout << "k = " << k << endl;
}

void RadixSort(int* arr, int n, int nums) {
	long long kx = 0;
	int** temp_arr = new int* [10];
	for (int i = 0; i < 10; i++)
		temp_arr[i] = new int[(int)(0.3 * n)];

	int* count = new int[10]{ 0 };

	int x;
	int exp = 1;
	kx += 2;

	for (int y = 0; y < nums; y++, exp *= 10) {
		kx += 4;
		for (int i = 0; i < 10; i++) {
			kx += 4;
			count[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			kx += 10;
			x = (arr[i] / exp) % 10;
			temp_arr[x][count[x]] = arr[i];
			count[x]++;
		}
		int k = 0;
		kx++;
		for (int i = 0; i < 10; i++) {
			kx += 3;
			for (int j = 0; j < count[i]; j++, k++) {
				kx += 6;
				arr[k] = temp_arr[i][j];
			}
		}
	}




	for (int i = 0; i < 10; i++) {
		kx += 3;
		delete[] temp_arr[i];
	}
	delete[] temp_arr;
	delete[] count;
	cout << "k: " << kx << endl;
}

void Swap(int* arr, int a, int b) {
	int x = arr[a];
	arr[a] = arr[b];
	arr[b] = x;
}

void Heapify(int* arr, int n, int cur, long long& k) {
	int temp = cur * 2 + 1;
	if (temp < n) {
		if (arr[cur] < arr[temp]) {
			k += 9;
			//swap(arr[cur], arr[temp]);
			Swap(arr, cur, temp);
			if (temp * 2 + 1 < n)
				Heapify(arr, n, (temp), k);
		}
	}
	temp++;
	k++;
	if (temp < n) {
		if (arr[cur] < arr[temp]) {
			k += 9;
			//swap(arr[cur], arr[temp]);
			Swap(arr, cur, temp);
			if (temp * 2 + 2 < n)
				Heapify(arr, n, (temp), k);
		}
	}
}


void HeapSort(int* arr, int n) {
	
	long long k = 0;

	for (int cur = ceil(n / 2); cur >= 0; cur--) {
		k += 3;
		Heapify(arr, n, cur, k);
	}
	//получили max heap

	for (int i = n - 1; i > 0; i--) {
		k += 6;
		Swap(arr, 0, i);
		//swap(arr[0], arr[i]);
		Heapify(arr, i, 0, k);
	}

	cout << "k: " << k << endl;
}

void Test() {
	int n = 10000;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10000;
		//cout << arr[i] << " ";
	}

	int* temp = new int[n];
	for (int i = 0; i < n; i++)
		temp[i] = arr[i];
	cout << "Random elements\n\n";
	Timer t;
	InsertionSort(temp, n);
	cout << "Insertion sort: " << t.elapsed() << endl;

	for (int i = 0; i < n; i++)
		temp[i] = arr[i];
	t.reset();
	RadixSort(temp, n, 4);
	cout << "Radix sort: " << t.elapsed() << endl;

	for (int i = 0; i < n; i++)
		temp[i] = arr[i];
	t.reset();
	HeapSort(temp, n);
	cout << "Heap sort: " << t.elapsed() << endl;
	cout << "---------------------------\n";
	cout << "Sorted elements\n\n";
	t.reset();
	InsertionSort(temp, n);
	cout << "Insertion sort: " << t.elapsed() << endl;
	t.reset();
	RadixSort(temp, n, 4);
	cout << "Radix sort: " << t.elapsed() << endl;
	t.reset();
	HeapSort(temp, n);
	cout << "Heap sort: " << t.elapsed() << endl;
	cout << "---------------------------\n";
	for (int i = 0; i < n / 2; i++) {
		int x = temp[i];
		temp[i] = temp[n - i - 1];
		temp[n - i - 1] = x;
	}
	for (int i = 0; i < n; i++)
		temp[i] = arr[i];
	cout << "Reverse order\n\n";
	t.reset();
	InsertionSort(temp, n);
	cout << "Insertion sort: " << t.elapsed() << endl;
	for (int i = 0; i < n; i++)
		temp[i] = arr[i];
	t.reset();
	RadixSort(temp, n, 4);
	cout << "Radix sort: " << t.elapsed() << endl;
	for (int i = 0; i < n; i++)
		temp[i] = arr[i];
	t.reset();
	HeapSort(temp, n);
	cout << "Heap sort: " << t.elapsed() << endl;
	delete[] arr;
	delete[] temp;
}

