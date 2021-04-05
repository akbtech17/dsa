// 2 - MoveAllNegativeAndPostive.cpp
// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

#include <iostream>
using namespace std;

void seperateElements(int arr[] , int n) {
	int negative = -1;
	int positive = n;

	int i = 0;
	while (i < n and i < positive) {
		if (arr[i] < 0) {
			swap(arr[i], arr[negative + 1]);
			negative++;
			i++;
		}
		else {
			swap(arr[i], arr[positive - 1]);
			positive--;
		}
	}
}

int main() {
	int arr[] = { -12, 11, -13, -5,
	              6, -7, 5, -3, 11
	            };
	int n  = sizeof(arr) / sizeof(int);

	seperateElements(arr, n);

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	return 0;
}