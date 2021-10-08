// left - right - shift - bruteforce.cpp
#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
	return;
}

void rightShift(int arr[], int n , int k) {
	int temp[n];
	for (int i = 0; i < n; ++i) temp[(i + k) % n] = arr[i];
	printArr(temp, n);
	return;
}

void leftShift(int arr[], int n, int k) {
	int temp[n];
	for (int i = 0; i < n; ++i) temp[(n + (i - k)) % n] = arr[i];
	printArr(temp, n);
	return;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);

	rightShift(arr, n, 3);
	leftShift(arr, n, 3);
	return 0;
}