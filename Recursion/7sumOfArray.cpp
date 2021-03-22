// 7sumOfArray.cpp
#include <iostream>
using namespace std;

int sumOfArr(int *arr, int n) {
	if (n == 0 ) return 0;
	return arr[0] + sumOfArr(arr + 1, n - 1);
}

int sumOfArr2(int* arr, int n ) {
	if (n == 0) return 0;
	return arr[n - 1] + sumOfArr2(arr, n - 1);
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);
	cout << sumOfArr(arr, n) << endl << sumOfArr2(arr, n);
	return 0;
}