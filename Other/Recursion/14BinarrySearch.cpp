// 14BinarrySearch.cpp
#include <iostream>
using namespace std;

int binarySearch(int*arr, int s, int e, int key ) {
	if (s > e) return -1;
	int m = (s + e) / 2;
	if (arr[m] == key) return m;
	else if (arr[m] < key)
		return binarySearch(arr, s, e - 1, key);
	return binarySearch(arr, s + 1, e, key);
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int key = 0;
	int n = sizeof(arr) / sizeof(int);
	cout << binarySearch(arr, 0, n - 1, key);
	return 0;
}