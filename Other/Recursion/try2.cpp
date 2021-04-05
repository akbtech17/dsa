#include <iostream>
#include <string>
using namespace std;

int doubleEndedString(string str1, string str2 ) {
	int ans = 0;
	int fre[26] = {0};
	for (int i = 0; i < str1.length(); ++i) {
		fre[str1[i] - 'a']++;
	}
	for (int i = 0; i < str2.length(); ++i) {
		fre[str2[i] - 'a']--;
	}

	for (int i = 0; i < 26; ++i) {
		if (fre[i] > 0) ans += fre[i];
		else ans += (-1 * fre[i]);
	}
	return ans;
}

int32_t main() {
	string str1, str2;
	// int n,k;

	int t;
	cin >> t;
	while (t--) {
		cin >> str1 >> str2;
		cout << doubleEndedString(str1, str2) << endl;
	}
	return 0;
}