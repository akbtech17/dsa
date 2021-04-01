// 5 - longest - palindromic - substring.cpp
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
	int s = 0;
	int e = str.size() - 1;

	while (s <= e) {
		if (str[s++] != str[e--]) return false;
	}
	return true;
}

string longestPalindromicSubstring(string str) {
	string ans = "";
	for (int i = 0; i < str.length(); ++i)
	{
		for (int j = i; j < str.length(); ++j)
		{
			string temp = str.substr(i, j - i + 1);
			if (isPalindrome(temp) and temp.size() > ans.size()) {
				ans = temp;
			}
		}
	}
	return ans;
}

int main() {
	string str;
	cin >> str;

	cout << longestPalindromicSubstring(str);

	return 0;
}