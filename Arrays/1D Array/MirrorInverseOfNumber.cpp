// MirrorInverseOfNumber.cpp
#include <iostream>
#include <vector>
#define ll long long
#define vi vector<int>
using namespace std;

bool checkInverse(ll num) {
	vi v;
	while (num > 0) {
		v.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0; i < v.size(); ++i) {
		if (v[v[i] - 1] != i + 1)return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll num;
		cin >> num;
		if (checkInverse(num))cout << "true\n";
		else cout << "false\n";
	}
	return 0;
}