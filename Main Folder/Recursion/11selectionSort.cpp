// 11selectionSort.cpp
#include <iostream>
using namespace std;

int FindTheMinIndx(int arr[], int n, int i) {
	int min_indx = i;
	for (int j = i + 1; j < n; ++j) {
		if (arr[j] < arr[min_indx]) min_indx = j;
	}
	return min_indx;
}

void SelectionSort(int* arr, int n, int i) {
	//base case
	if (i == n - 1) return;
	//recursive case
	int min_indx = FindTheMinIndx(arr, n, i);
	if (i != min_indx)
		swap(arr[i], arr[min_indx]);
	SelectionSort(arr, n, i + 1);
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
	SelectionSort(a, n, 0);
	PrintArr(a, n);
	return 0;
}