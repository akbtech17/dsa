// 5 - CountOccOfSubstringInString.cpp
#include <iostream>
#include <string>
using namespace std;

int countOcc(string s, string p) {
	int cnt = 0;

	for (int i = 0; i <= s.length() - p.length(); ++i) {
		int j = 0;
		for (; j < p.length(); ++j) {
			if (s[i + j] != p[j]) break;
		}
		if (j == p.length()) cnt++;
	}
	return cnt;
}

int main() {
	string str = "aaa";
	string pat = "a";
	cout << countOcc(str, pat);
	return 0;
}