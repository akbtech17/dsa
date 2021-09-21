// 6_LongestSubstringWithKUniqueChars.cpp
// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0#

// TC - O(N)
// SC - O(1)

#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubs(string str, int k) {
	int ans = 0;

	//make character map to store the calculations
	int mp[26] = {0};

	int i = 0;
	int j = 0;
	int dist_char_so_far = 0;

	while (j < str.length()) {
		//calculations
		if (mp[str[j] - 'a'] == 0) dist_char_so_far++;
		mp[str[j] - 'a']++;

		if (dist_char_so_far < k) {
			j++;
		}
		else if (dist_char_so_far == k) {
			ans = max(ans, j - i + 1);
			j++;
		}
		else {
			while (dist_char_so_far > k) {
				//remove calculations for i
				mp[str[i] - 'a']--;
				if (mp[str[i] - 'a'] == 0) dist_char_so_far--;
				i++;
			}
			j++;
		}
	}
	if (ans == 0) return -1;
	return ans;
}

int main() {
	//input string and k
	string str;
	int k ;
	cin >> str;
	cin >> k;

	cout << lengthOfLongestSubs(str, k);

	return 0;
}