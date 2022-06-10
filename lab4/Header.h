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
	for (int i = 1; i < n; i++) {

		int temp = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > temp) {
				arr[j + 1] = arr[j];
			}
			else {
				arr[j + 1] = temp;
				break;
			}
			if (temp < arr[0])
				arr[0] = temp;

		}
		/*for (int k = 0; k < n; k++)
			cout << arr[k] << " ";
		cout << "\n\n";*/

	}

}

void RadixSort(int* arr, int n, int nums) {
	int** temp_arr = new int* [10];
	for (int i = 0; i < 10; i++)
		temp_arr[i] = new int[(int)(0.3 * n)];

	int* count = new int[10]{ 0 };

	int x;
	int exp = 1;

	for (int y = 0; y < nums; y++, exp *= 10) {
		for (int i = 0; i < 10; i++)
			count[i] = 0;

		for (int i = 0; i < n; i++) {
			x = (arr[i] / exp) % 10;
			temp_arr[x][count[x]] = arr[i];
			count[x]++;
		}
		int k = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < count[i]; j++, k++) {
				arr[k] = temp_arr[i][j];
			}
		}
	}




	for (int i = 0; i < 10; i++)
		delete[] temp_arr[i];
	delete[] temp_arr;
	delete[] count;
}

void Heapify(int* arr, int n, int cur) {
	if (cur * 2 + 1 < n) {
		if (arr[cur] < arr[cur * 2 + 1]) {
			swap(arr[cur], arr[cur * 2 + 1]);
			Heapify(arr, n, (cur * 2 + 1));
		}
	}
	if (cur * 2 + 2 < n) {
		if (arr[cur] < arr[cur * 2 + 2]) {
			swap(arr[cur], arr[cur * 2 + 2]);
			Heapify(arr, n, (cur * 2 + 2));
		}
	}
}


void HeapSort(int* arr, int n) {
	//int x = round(4.7);

	int cur = ceil(n / 2) - 1; //номер текущего элемента, последний НЕ лист

	for (; cur >= 0; cur--) {
		Heapify(arr, n, cur);
	}
	//получили max heap

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}


}

