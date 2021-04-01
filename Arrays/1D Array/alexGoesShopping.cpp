// alexGoesShopping.cpp
#include <iostream>
#include <algorithm>
using namespace std;

bool isShopkeeperCorrect(int* arr, int n, int money, int k) {
	int total_items = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] <= money) {
			for (int j = i; j < n; ++j) {
				if (money >= arr[i]) {
					money -= arr[i];
					total_items++;
				}
			}
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int q;
	cin >> q;
	while (q--) {
		int money, k;
		cin >> money >> k;
		if (isShopkeeperCorrect(arr, n, money, k)) cout << "Yes\n";
		else cout << "No\n";
	}


	return 0;
}