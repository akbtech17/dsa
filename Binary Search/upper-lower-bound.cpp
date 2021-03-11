// upper - lower - bound.cpp
#include <iostream>
#define ll long long
#define MX 100000
using namespace std;

int binarySearchUpper(ll arr[], int s, int e, ll key) {
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

int binarySearchLower(ll arr[], int s, int e, ll key) {
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
	ll arr[MX] = {0};
	int n;

	//input array
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];


	int q;
	cin >> q;

	while (q--) {
		ll key;
		cin >> key;
		cout << binarySearchLower(arr, 0, n - 1, key) << " " << binarySearchUpper(arr, 0, n - 1, key) << endl;
	}
	return 0;
}