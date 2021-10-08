// 5 - LongestPalindromicSubstring.cpp
//Recursive Approach
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
	int s = 0;
	int e = str.size() - 1;
	while (s < e) {
		if (str[s++] != str[e--]) return false;
	}
	return true;
}

void recurse(string str, string &ans, int i = 0) {
	if (i == str.size()) return;

	for (int j = i; j < str.size(); ++j) {
		if (isPalindrome(str.substr(i, j)) and j - i + 1 > ans.size()) {
		
			ans = str.substr(i, j);
		}
	}

	recurse(str, ans, i + 1);
	return;
}

string longestPalindromicSubstring(string str) {
	string ans = "";
	recurse(str, ans);
	return ans;
}

int main() {
	string str = "abcba";
	cout << longestPalindromicSubstring(str);
	return 0;
}