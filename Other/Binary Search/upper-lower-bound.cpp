// upper - lower - bound.cpp
#include <iostream>
#include <string.h>
#define ll long long
#define MX 100000
using namespace std;

int binarySearchUpper(int arr[], int s, int e, int key) {
	int ans = -1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (key == arr[m]) {
			ans = m;
			s = m + 1;
		}
		else if (key < arr[m]) {
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	return ans;
}

int binarySearchLower(int arr[], int s, int e, int key) {
	int ans = -1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (key == arr[m]) {
			ans = m;
			e = m - 1;
		}
		else if (key < arr[m]) {
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	return ans;
}

int main() {
	// ll arr[MX] = {0};
	int n;

	//input array
	cin >> n;
	int key;
	cin >> key;
	int *arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) cin >> arr[i];



	cout << binarySearchLower(arr, 0, n - 1, key) << " " << binarySearchUpper(arr, 0, n - 1, key) << endl;

	return 0;
}