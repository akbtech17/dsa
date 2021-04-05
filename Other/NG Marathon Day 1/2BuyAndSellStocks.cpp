// 2BuyAndSellStocks.cpp
#include <iostream>
#include <algorithm>
using namespace std;


void TellWhenToBuyNSell(int arr[], int n) {

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[i] < arr[j]) {
				cout << "Buy in " << arr[i] << " and sell in " << arr[j];
				cout << " to get profit of " << arr[j] - arr[i] << endl;
			}
		}
	}
	return;
}

int main() {
	int arr1[] = {100, 180, 260, 310, 40, 535, 695};
	int n1 = sizeof(arr1) / sizeof(int);
	// int arr2[] = {10, 21, 22, 100, 101, 200, 300};
	// int n2 = sizeof(arr2) / sizeof(int);

	TellWhenToBuyNSell(arr1, n1);
	// TellWhenToBuyNSell(arr2, n2);

	return 0;
}