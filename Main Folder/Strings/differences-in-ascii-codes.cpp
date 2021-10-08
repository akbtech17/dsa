// differences - in - ascii - codes.cpp
#include <iostream>
#include <string>
using namespace std;

string findDifference(string str) {
	string ans;

	for (int i = 0; i < str.length(); i++) {
		if ( i == 0) {
			ans.push_back(str[i]);
			continue;
		}
		int diff = str[i] - str[i - 1];
		string diff_str = to_string(diff);
		ans.append(diff_str);
		ans.push_back(str[i]);
	}

	return ans;
}

int main() {
	string str;
	cin >> str;

	cout << findDifference(str);

	return 0;
}