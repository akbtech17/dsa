#include <iostream>
#include <algorithm>
using namespace std;

void c_p_c() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int makeChange(int money, int *coins, int n) {
	int ans = 0;
	while (money > 0) {
		int idx = upper_bound(coins, coins + n, money) - coins - 1;
		money -= coins[idx];
		cout << coins[idx] << "+";
		ans++;
	}
	return ans;
}

int main() {
	// c_p_c();
	int money;
	cin >> money;
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
	int n = sizeof(coins) / sizeof(int);
	cout << "\nNo of Coins :: " << makeChange(money, coins, n);
	return 0;
}