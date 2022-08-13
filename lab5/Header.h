#pragma once
#include <iostream>
#include <string>
using namespace std;


int LinearSearch(int* arr, int n, int x, int& k) {
	k = 0;
	for (int i = 0; i < n; i++) {
		k += 4;
		if (arr[i] == x)
			return i;
	}
	return -1;
}


int LinearSearchBarrier(int* arr, int n, int x, int& k) {
	k = 0;
	if (arr[n - 1] == x) {
		k += 3;
		return n - 1;
	}
	int temp = arr[n - 1];
	arr[n - 1] = x;
	int pos = 0;
	k += 4;

	while (arr[pos] != x) {
		k += 2;
		pos++;
	}
	arr[n - 1] = temp;
	if (pos == (n - 1)) {
		k += 4;
		return -1;
	}
	else
		return pos;
}


int BinarySearch(int* arr, int n, int x, int& k) {
	k = 0;
	int a = 0, b = n - 1;
	int mid = 0;
	k += 3;
	while (true) {
		mid = (a + b) / 2;

		if (x < arr[mid]) {
			k += 4;
			b = mid - 1;
		}
		else if (x > arr[mid]) {
			k += 4;
			a = mid + 1;
		}
		else
			return mid;
		k += 2;
		if (a > b)
			return -1;
		k++;
	}
}


int SimpleSearch(char s[], char q[], int& count) {
	count = 0;
	int N = strlen(s);
	int M = strlen(q);
	int k = -1; //позиция
	int j = 0;
	count += 4;
	do {
		k++;
		j = 0;
		count += 2;
		while (j < M && s[k + j] == q[j]) {
			j++;
			count += 5;
		}
		if (j == M)
			return k;
		count += 2;
	} while (k < N - M);
	return -1;
}

int BMSearch(char str[], char substr[], int& count) { //бойнра-мура
	count = 0;
	int n = strlen(str);
	int m = strlen(substr);
	int i, pos;
	int BMT[256];
	for (int i = 0; i < 255; i++)
		BMT[i] = m;
	count += 260;
	for (int i = m - 1; i >= 0; i--) {
		count += 4;
		if (BMT[(short)(substr[i])] == m)
			BMT[(short)(substr[i])] = m - i - 1;
	}
	pos = m - 1;

	while (pos < n) {
		if (substr[m - 1] != str[pos])
			pos = pos + BMT[(short)(str[pos])];
		else
			for (i = m - 2; i >= 0; i--) {
				count += 6;
				if (substr[i] != str[pos - m + i + 1]) {
					pos += BMT[(short)(str[pos - m + i + 1])] - 1;
					break;
				}
				else
					if (i == 0)
						return pos - m + 1;
				//cout << "\t" << i << endl;
			}
	}
	if (pos > n - m)
		return -1;
	return pos;

}


int KMPSearch(char s[], char p[], int& count) //кнутта-морриса-пратта
{
	count = 0;
	int i, j, N, M;
	N = strlen(s);
	M = strlen(p);

	int* temp = new int[M];
	count += 4;

	temp[0] = 0;
	for (i = 1, j = 0; i < M; i++)
	{
		count += 3;
		while (j > 0 && p[j] != p[i]) {
			count += 3;
			j = temp[j - 1];
		}
		if (p[j] == p[i])
			j++;
		temp[i] = j;
		count += 3;
	}

	
	for (i = 0, j = 0; i < N; i++)
	{
		count += 3;
		while (j > 0 && p[j] != s[i]) {
			count += 3;
			j = temp[j - 1];
		}
		if (p[j] == s[i])
			j++;
		if (j == M)
		{
			delete[] temp;
			return i - j + 1;
		}
		count += 3;
	}
	delete[] temp;
	return -1;
}



void rabin_karp(string& text, string& pattern, int q, int& count)
{
	count = 0;
	
	int m = pattern.length();
	
	int n = text.length();
	int p = 0, t = 0, h = 1, d = 26;
	
	count += 5;
	for (int i = 0; i < m - 1; i++)
	{
		count += 5;
		h = (h * d) % q;
	}
	
	for (int i = 0; i < m; i++)
	{
		count += 9;
		p = (d * p + pattern[i]) % q; //хеш для подстроки
		t = (d * t + text[i]) % q; //хеш для строки
	}
	
	for (int i = 0; i <= n - m; i++)
	{
		count += 3;
		if (p == t)
		{
			int flag = 0;
			for (int j = 0; j < m; j++)
			{
				count += 4;
				if (text[i + j] != pattern[j])
				{
					flag = 1;
					break;
				}
			}
			
			if (flag == 0)
			{
				cout << "Позиция: " << i << endl;
			}
		}
		
		if (i < n - m)
		{
			t = (d * (t - text[i] * h) + text[i + m]) % q;
			count += 7;
			if (t < 0)
			{
				t = (t + q);
			}
		}
	}
}