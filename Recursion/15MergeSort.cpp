// 15MergeSort.cpp
#include <iostream>
#define MX 100005
using namespace std;

void mergeArrays(int *arr, int s, int e) {
	int temp[MX] = {0};
	int m = (s + e) / 2;
	int i = s;
	int k = s;
	int j = m + 1;

	while (i <= m and j <= e) {
		if (arr[i] <= arr[j]) {
			temp[k++]  = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= m) {
		temp[k++] = arr[i++];
	}

	while (j <= e) {
		temp[k++] = arr[j++];
	}

	for (i = s; i <= e; ++i) {
		arr[i] = temp[i];
	}
	return;
}

void mergeSort(int *arr, int s, int e) {
	if (s >= e) return;
	//divide
	int m = (s + e) / 2;
	//sort
	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);
	//merge
	mergeArrays(arr, s, e);
	return;
}

void print(int*arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[MX];
	int n ;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	print(arr, n);
	return 0;
}