// binary - search - recursive.cpp
#include <iostream>
#define ll long long
#define MX 100000
using namespace std;

int binarySearchRecursive(ll arr[], int s, int e, ll key) {
	//base case
	if (s > e)  return -1;
	int m = (s + e) / 2;
	//if the key is found
	if (arr[m] == key) return m;
	else if (key < arr[m]) return binarySearchRecursive(arr, s, m - 1, key);
	return binarySearchRecursive(arr, m + 1, e, key);
}

int main() {
	ll arr[MX] = {0};
	int n;

	//input array
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ll key;
	cin >> key;

	cout << binarySearchRecursive(arr, 0, n - 1, key);

	return 0;
}