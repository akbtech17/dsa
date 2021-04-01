// 1permutations.cpp
#include<iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

vector<string> ans;

int countPermutation(string str, int i = 0) {
	if (i == str.length()) {
		return 1;
	}
	int ans = 0;
	for (int j = i; j < str.length(); ++j)
	{
		swap(str[i], str[j]);
		ans += countPermutation(str, i + 1);
		//backtrack
		swap(str[i], str[j]);
	}
	return ans;
}

void permute(string str, int i = 0) {
	if (i == str.length()) {
		ans.push_back(str);
		return;
	}
	for (int j = i; j < str.length(); ++j)
	{
		swap(str[i], str[j]);
		permute(str, i + 1);
		//backtrack
		swap(str[i], str[j]);
	}
	return ;
}

int main() {
	string str;
	cin >> str;
	permute(str);
	sort(ans.begin(), ans.end());

	cout << countPermutation(str) << endl;
	for (auto el : ans)
		cout << el << " ";
	return 0;
}