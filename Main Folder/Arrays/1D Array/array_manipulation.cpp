// array_manipulation.cpp

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 10 3
// 1 5 3
// 4 8 7
// 6 9 1

int main() {
	int n;
	cin >> n;
	int q;
	cin >> q;
	vector<vector<int>> v1;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = 0;
	}
	int ans = 0;

	while (q--) {
		int a, b, val;
		cin >> a >> b >> val;
		for (int i = a - 1; i <= b - 1; i++) {
			v[i] += val;
		}
		// for (auto el : v) cout << el << " ";
		// cout << endl;
	}

	for (auto el : v) ans = max(ans, el);
	cout << ans;
	return 0;
}