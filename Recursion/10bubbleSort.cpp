// 10bubbleSort.cpp
#include <iostream>
using namespace std;

void BubbleSort(int* arr, int n, int i, int j) {
	//base case
	if (i == n - 1) return;
	if (j >= n - 1) {
		BubbleSort(arr, n, i + 1, 0);
	}
	//recursive case

	else {
		if (arr[j] > arr[j + 1])
			swap(arr[j], arr[j + 1]);

		BubbleSort(arr, n, i , j + 1);
	}
	return;
}

void PrintArr(int *arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return ;
}

int main() {
	int a[] = {2, 3, 1, 4, 8, 7, 6};
	int n = sizeof(a) / sizeof(int);
	PrintArr(a, n);
	BubbleSort(a, n, 0, 0);
	PrintArr(a, n);
	return 0;
}