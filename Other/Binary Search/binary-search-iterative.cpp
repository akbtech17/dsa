// binary - search - iterative.cpp
#include <iostream>
#define ll long long
#define MX 100000
using namespace std;

int binarySearchIterative(ll arr[], int n, ll key) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int m = (s + e) / 2;
		if (arr[m] == key) return m;
		else if (key < arr[m]) e = m - 1;
		else s = m + 1;
	}

	return -1;
}

int main() {
	ll arr[MX] = {0};
	int n;

	//input array
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ll key;
	cin >> key;

	cout << binarySearchIterative(arr, n, key);

	return 0;
}