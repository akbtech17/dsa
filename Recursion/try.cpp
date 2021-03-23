// subsets.cpp
#include <iostream>
#include <vector>
#define pb push_back
#define mp make_pair
#define vi vector<int>
using namespace std;

// void printSubsets(vi v, int n, int target, vi ans = {}, int sum = 0) {
// 	return;
// }

int main() {
	int n = 0, target = 0;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cin >> target;
	printSubsets(v, n, target);
	return 0;
}