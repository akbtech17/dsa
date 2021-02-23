#include <iostream>
#include <algorithm>
using namespace std;

bool mycomp(string s1, string s2) {
	string s12 = s1.append(s2);
	string s21 = s2.append(s1);
	return s12 > s21;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string arr[105];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n, mycomp);
		for (auto el : arr) cout << el;
		cout << endl;
	}
	return 0;
}