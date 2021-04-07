// 8 - SplitTheBinaryStrings.cpp
// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/

#include <iostream>
#include <string>
using namespace std;

int maxBalancedStrings(string str) {
	int ans = 0;
	int cnt0 = 0;
	int cnt1 = 0;

	for (int i = 0; i < str.size(); i++) {
		//include curr char in calculation
		if (str[i] == '0') cnt0++;
		else cnt1++;
		if (cnt0 == cnt1) ans++;
	}
	return cnt0 != cnt1 ? -1 : ans;
}

int main() {
	string str = "0100110101";
	cout << maxBalancedStrings("0100110101") << endl;
	cout << maxBalancedStrings("0111100010") << endl;

	return 0;
}