// 9removeDuplicatesFromSortedArray.cpp
#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n, int i = 0 , int j = 0) {
	//base case
	if (i == n) return j;
	//recursive work
	if (i > 0 and arr[i - 1] == arr[i]) {
		return removeDuplicates(arr, n, i + 1, j);
	}
	else {
		arr[j++] = arr[i++];
		return removeDuplicates(arr, n, i , j);
	}
	return 0;
}

int main() {
	int arr[] = {5, 5, 5};
	int n  = sizeof(arr) / sizeof(int);
	int j = removeDuplicates(arr, n);

	for (int i = 0; i < j; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}