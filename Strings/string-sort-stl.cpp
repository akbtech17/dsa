// string - sort - stl.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool mycomp(string s1, string s2) {
	if (s2.find(s1) == 0 and s2.length() > s1.length()) return false; //swap is required
	if (s1.find(s2) == 0 and s2.length() < s1.length()) return true; //no swap
	return s1 < s2; //no swap
}

int main() {
	int n;
	cin >> n;
	string arr[1005];
	for (int i = 0; i < n; ++i) cin >> arr[i];

	sort(arr, arr + n, mycomp);

	for (auto str : arr) cout << str << endl;

	return 0;
}