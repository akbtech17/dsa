// 3 - RotateAnArrayByOne.cpp
// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

#include <iostream>
using namespace std;

void rotateByOne(int arr[] , int n) {
	int rot  = -1;
	for (int i = 0; i < n; ++i) {
		int new_idx = (rot + i + n) % n;
		cout << arr[new_idx] << " ";
	}
	return ;
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int n  = sizeof(arr) / sizeof(int);

	rotateByOne(arr, n);

	return 0;
}