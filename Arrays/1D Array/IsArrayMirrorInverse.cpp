// IsArrayMirrorInverse.cpp
#include <iostream>
#include <vector>
#define ll long long
#define vi vector<int>
using namespace std;

bool checkInverse(vi  v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[v[i]] != i)return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	if (checkInverse(v))cout << "true\n";
	else cout << "false\n";

	return 0;
}