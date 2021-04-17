// 4 - KMergeArrays.cpp
#include <iostream>
#include <algorithm>
using namespace std;

int* mergeKSortedArrs(int arr1[], int n1, int arr2[], int n2, int arr3[], int n3) {
	int *arr = new int[n1 + n2 + n3];
	int k = 0;
	for (int i = 0; i < n1; ++i) arr[k++] = arr1[i];
	for (int i = 0; i < n2; ++i) arr[k++] = arr2[i];
	for (int i = 0; i < n3; ++i) arr[k++] = arr3[i];

	sort(arr, arr + k);
	return arr;
}

int main() {
	int arr1[] = {1, 4, 8};
	int n1 = sizeof(arr1) / sizeof(int);
	int arr2[] = {3, 5, 7};
	int n2 = sizeof(arr2) / sizeof(int);
	int arr3[] = {8, 9, 10};
	int n3 = sizeof(arr3) / sizeof(int);

	int *arr = mergeKSortedArrs(arr1, n1, arr2, n2, arr3, n3);
	int n = n1 + n2 + n3;

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	return 0;
}
