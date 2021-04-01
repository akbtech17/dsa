// kthRoot.cpp
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll computeKthRoot(ll n , ll k) {
	ll ans = 0;
	ll s = 0;
	ll e = n;

	while (s <= e) {
		ll mid = (s + e) / 2;
		if (pow(mid, k) == n) {
			ans = mid;
			break;
		}
		else if (pow(mid, k) < n) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		ll k;
		cin >> n >> k;
		cout << computeKthRoot(n, k) << endl;
	}

	return 0;
}