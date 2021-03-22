// rearrange - string - characters.cpp
#include <iostream>
using namespace std;

string solve(string str) {
	int freq[26] = {0};
	int n = str.length();
	for (int i = 0; i < n; ++i)
		freq[str[i] - 'a'] += 100;
	for (int i = 0; i < 26; ++i)
	{
		if (freq[i])
		}


	return ans;
}

int main() {
	string str;
	cin >> str;

	cout << solve(str) << endl;

	return 0;
}