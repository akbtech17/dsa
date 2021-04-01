// IsSecondArrayMirrorInverseOfFirstArray.cpp
#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

bool isAMirrorInverseOfB(vi a, vi b) {
	for (int i = 0; i < a.size(); ++i) {
		if (b[a[i]] != i) return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	vi a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	if (isAMirrorInverseOfB(a, b))cout << "true";
	else cout << "false";
	return 0;
}