// sqaure - root.cpp
#include <iostream>
#define ll long long
#define MX 1000000
using namespace std;

ll squareRoot(ll num) {
	ll s = 0;
	ll e = num;
	ll ans = 0;
	while (s <= e) {
		ll m = (s + e) / 2;
		if ((m * m) == num) {
			ans = m;
			break;
		}
		else if ((m * m) > num) {
			e = m - 1;
		}
		else {
			ans = m;
			s = m + 1;
		}
	}
	return ans;
}



int main() {
	ll num;
	cin >> num;

	cout << squareRoot(num);

	return 0;
}