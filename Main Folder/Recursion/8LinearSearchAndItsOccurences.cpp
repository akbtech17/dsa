// 8LinearSearchAndItsOccurences.cpp
#include <iostream>
using namespace std;

bool isPresent(int arr[], int n , int key) {
	if (n == 0 ) return false;
	if (arr[0] == key) return true;
	return isPresent(arr + 1, n - 1, key);
}

int firstOcc(int arr[], int n, int key, int i = 0) {
	if (i == n) return -1;
	if (arr[i] == key) return i;
	return firstOcc(arr, n, key, i + 1);
}

int lastOcc(int arr[], int n, int key, int i) {
	if (i == -1) return -1;
	if (arr[i] == key) return i;
	return lastOcc(arr, n, key, i + 1);
}
int lastOcc2(int arr[], int n , int key, int i = 0; int ans = -1) {
	if ()
	}

void printAllOcc(int arr[], int n, int key, int i = 0) {
	if (i == n) return;
	if (arr[i] == key) cout << i << " ";
	printAllOcc(arr, n, key, i + 1);
	return;
}

int main() {
	int arr[] = {1, 2, 5, 4, 5};
	int key = 5;
	int n = sizeof(arr) / sizeof(int);
	if (isPresent(arr, n, key))
		cout << key << " is isPresent in arr\n";
	else cout << key << " is not present in arr\n";
	cout << "first occ of " << key << " in arr is : " << firstOcc(arr, n, key) << endl;
	cout << "last occ of " << key << " in arr is : " << lastOcc(arr, n, key, n - 1) << endl;
	cout << "last occ of " << key << " in arr are : ";
	printAllOcc(arr, n, key);
	return 0;
}