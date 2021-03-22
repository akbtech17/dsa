// pairOfRoses.cpp
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// 2
// 2
// 40 40
// 80
// 5
// 10 2 6 8 4
// 10

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, prices[100000] = {0}, target;
		cin >> n;
		for (int i = 0; i < n; i++)cin >> prices[i];
		cin >> target;
		int price1, price2;
		int min_diff_so_far = INT_MAX;
		sort(prices, prices + n);
		int s = 0;
		int e = n - 1;
		while (s < e) {
			if (prices[s] + prices[e] == target) {
				int curr_diff = prices[e] - prices[s];
				if (curr_diff < min_diff_so_far) {
					price1 = prices[s];
					price2 = prices[e];
					min_diff_so_far = curr_diff;
				}
				s++;
			}
			else if (prices[s] + prices[e] < target) s++;
			else e--;
		}
		cout << price1 << " and " << price2 << endl;
	}
	return 0;
}