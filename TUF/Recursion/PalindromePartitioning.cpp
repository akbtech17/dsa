#include <iostream>
using namespace std;

// Approach: Recursion + Backtracking
// TC: O(2^N)
// SC: O(N)
class Solution {
public:
	bool checkPalindrome(string str) {
		int s = 0, e = str.size() - 1;
		while (s < e) {
			if (str[s] != str[e]) return false;
			s++;
			e--;
		}
		return true;
	}

	void recurse(string str, int i, vector<string> path,
				 vector<vector<string>> &paths) {
		// Base Case
		if (i >= str.size()) {
			paths.push_back(path);
			return;
		}

		for (int j = i; j < str.size(); j++) {
			string subStr = str.substr(i, j - i + 1);
			if (checkPalindrome(subStr) == false) continue;
			path.push_back(subStr);
			recurse(str, j + 1, path, paths);
			path.pop_back();
		}

		return;
	}

	vector<vector<string>> partition(string str) {
		vector<vector<string>> paths;
		vector<string> path;
		recurse(str, 0, path, paths);
		return paths;
	}
};