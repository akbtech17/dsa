// min - window - substring.cpp
#include <iostream>
#include <map>
using namespace std;

string minWindow(string s, string t) {
	map<char, int> mp;
	for (auto ch : t) {
		mp[ch]++;
	}
	int req_ch = t.size();

	int i = 0;
	int j = 0;
	string ans = "";
	bool isAnyAnsFound = false;
	while (j < s.size()) {
		//add calculations for curr char
		if (mp.count(s[j]) != 0) {
			if (mp[s[j]] > 0) {
				mp[s[j]]--;
				req_ch--;
			}
			else mp[s[j]]--;
		}

		//if the window is found
		if (req_ch == 0) {
			//try shrinking window
			while (req_ch == 0 and i <= j) {
				if (mp.count(s[i]) != 0) {
					if (mp[s[i]] < 0) {
						mp[s[i]]++;
					}
					else {
						mp[s[i]]++;
						req_ch++;
					}
				}
				i++;
			}
			i--;
			//extract the substring
			string candidate = s.substr(i, j - i + 1);
			if (isAnyAnsFound == false) ans = candidate, isAnyAnsFound = true;
			else {
				if (candidate.size() < ans.size()) ans = candidate;
			}
		}
		j++;
	}

	return ans;
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << minWindow(s, t);
	return 0;
}
