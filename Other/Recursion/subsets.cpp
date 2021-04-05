// subsets.cpp
#include <iostream>
#include <vector>
#include<set>
#include<algorithm>
#define vi vector<int>
#define pb push_back
using namespace std;

vector<vector<int>> va;
void printSubsets(vi v, int n, int target, vi ans, bool isIncluded = false, int sum = 0) {
	if (n == 0) {
		if (isIncluded and sum == target) {
			// for (auto el : ans)	cout << el << " ";
			// cout << endl;
			va.pb(ans);
		}
		return;
	}
	printSubsets(v, n - 1, target, ans, isIncluded, sum);
	ans.pb(v[n - 1]);
	printSubsets(v, n - 1, target, ans, true, sum + v[n - 1]);

	return;
}

bool compare(vi a, vi b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
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

	sort(va.begin(), va.end(), compare);
	for (auto v : va) {
		for (auto el : v) cout << el << " ";
		cout << endl;
	}
	return 0;
}