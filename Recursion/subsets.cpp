// subsets.cpp
#include <iostream>
#include <vector>
#define vi vector<int>
#define pb push_back
using namespace std;

void printSubsets(vi v, int n, int target, vi ans, bool isIncluded = false, int sum = 0) {
	if (n == 0) {
		if (isIncluded and sum == target) {
			for (auto el : ans)	cout << el << " ";
			cout << endl;
		}
		return;
	}
	printSubsets(v, n - 1, target, ans, isIncluded, sum);
	ans.pb(v[n - 1]);
	printSubsets(v, n - 1, target, ans, true, sum + v[n - 1]);

	return;
}

int main() {
	int n, target;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	cin >> target;
	vi ans;
	printSubsets(v, n, target, ans);
	return 0;
}