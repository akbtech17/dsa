// twins.cpp
#include <iostream>
#include <string>
using namespace std;

void countTwins(string str, int* fre, int i = 0) {
	if ( i == str.length()) return;
	fre[str[i] - 'A']++;
	countTwins(str, fre, i + 1);
	return;
}

int main() {
	string str;
	cin >> str;

	int fre[26] = {0};

	countTwins(str, fre);
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		if (fre[i] > 0) {
			ans += fre[i] - 1;
		}
	}

	cout << ans;
	return 0;
}