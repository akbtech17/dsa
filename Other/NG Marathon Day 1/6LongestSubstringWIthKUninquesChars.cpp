// 6LongestSubstringWIthKUninquesChars.cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

int LongestSub(string str, int k) {
	int max_len_so_far = 0;

	int un_ch = 0;
	map<char, int> mp;

	int i = 0;
	int j = 0;
	int n = str.size();
	while (j < n) {
		//calculations
		if (mp.count(str[j]) == 0 or mp[str[j]] == 0) {
			un_ch++;
		}
		mp[str[j]]++;

		if (un_ch < k) j++;
		else if (un_ch == k) {
			max_len_so_far = max(max_len_so_far, j - i + 1);
			j++;
		}
		else {
			while (un_ch > k) {
				//remove calculations for the first char
				mp[str[i]]--;
				if (mp[str[i]] == 0) {
					un_ch--;
				}
				i++;
			}
			j++;
		}
	}
	return max_len_so_far;
}

int main() {
	cout << LongestSub("aabbcc", 1) << endl;
	cout << LongestSub("aabbcc", 2) << endl;
	cout << LongestSub("aabacbebebe", 3) << endl;

	return 0;
}