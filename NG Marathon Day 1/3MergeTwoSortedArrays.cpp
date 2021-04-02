// 3MergeTwoSortedArrays.cpp
#include <iostream>
using namespace std;


void MergeTwoSortedArrays(int arr1[], int n1, int arr2[], int n2) {
	int i = n1 - 1;
	int j = n2 - 1;
	int k = n1 + n2 - 1;

	while (i >= 0 and j >= 0) {
		if (arr1[i] > arr2[j]) arr1[k--] = arr1[i--];
		else arr1[k--] = arr2[j--];
	}

	while (j >= 0) {
		arr1[k--] = arr2[j--];
	}

	// print arr1
	for (int itr = 0; itr <= n1 + n2 - 1; ++itr) {
		cout << arr1[itr] << " ";
	}
	return ;
}

int main() {
	int arr1[100000] = {1, 2, 3, 4, 5};
	int n1 = 5;
	int arr2[] = {6, 7, 8};
	int n2 = sizeof(arr2) / sizeof(int);

	MergeTwoSortedArrays(arr1, n1, arr2, n2);

	return 0;
}