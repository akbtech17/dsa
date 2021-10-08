// 4 - LongestSubstringWithoutRepeatingChars.cpp
#include <iostream>
#include <cstring>
using namespace std;

bool hasUniqueChar(string str) {
	bool mp[256] = {0};
	for (int k = 0; k < str.size(); ++k) {
		if (mp[str[k]]) {
			return false;
		}
		mp[str[k]] = true;
	}
	return true;
}

int longestSubstring1(string &str) {
	int n = str.size();
	int s = -1;
	int e = -1;
	int len = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int clen = j - i + 1;
			if (clen > len and hasUniqueChar(str.substr(i, clen))) {
				len = clen;
				s = i;
				e = j;
			}
		}
	}
	//print the required substring
	for (int i = s; i <= e; ++i) {
		cout << str[i];
	}
	return len;
}

//sliding window
int longestSubstring2(string &str) {
	int s = 0;
	int e = 0;
	int i, j;
	bool mp[256] = {0};
	int ans = 0;
	while (e < str.size()) {
		if (mp[str[e]] == false) {
			mp[str[e]] = true;
			//store ans
			if (e - s + 1 > ans) {
				i = s;
				j = e;
				ans = e - s + 1;
			}
			e++;
		}
		else {
			///contract
			mp[str[s]] = false;
			s++;
		}
	}

	for (int k = i; k <= j; ++k) {
		cout << str[k];
	}
	return ans;
}

int longestSubstring3(string &str) {
	int s = 0;
	int e = 0;
	int i, j;
	//map to store the last occurence of each window
	int mp[256];
	for (int i = 0; i < 256; i++) mp[i] = -1;
	int ans = 0;

	//curr cha rko daldo map me
	mp[str[0]] = 0;
	ans = 1;
	int clen = 1;
	e = 1;

	while (e < str.size()) {
		int last_occ = mp[str[e]];
		if (mp[str[e]] == -1 or last_occ < e - clen) { //if the curr char is not vis
			//expand window
			clen++;
		}
		else { // if it has been occured before
			///contract
			clen = i - last_occ;
		}

		mp[str[e]] = e;
		ans = max(ans, clen);
	}

	// for (int k = i; k <= j; ++k) {
	// 	cout << str[k];
	// }
	return ans;
}

void tell(string str) {
	// cout << longestSubstring1(str) << endl;
	// cout << longestSubstring2(str) << endl;
	cout << longestSubstring3(str) << endl;

	return;
}

int main() {
	// tell("aba");
	tell("abcbca");

	return 0;
}