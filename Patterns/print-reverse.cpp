// print - reverse.cpp
#include <iostream>
#define ll long long
using namespace std;

int main() {
	ll num;
	cin >> num;
	ll ans = 0;
	while (num > 0) {
		ans += num % 10;
		num /= 10;
		ans *= 10;
	}
	ans /= 10;
	cout << ans;
	return 0;
}