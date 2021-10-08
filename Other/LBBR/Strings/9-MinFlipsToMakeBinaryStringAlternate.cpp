// 9 - MinFlipsToMakeBinaryStringAlternate.cpp
// https://www.geeksforgeeks.org/number-flips-make-binary-string-alternate/
#include <iostream>
#include <string>
using namespace std;

int minFlips(string str) {
	int cnt1 = 0;
	int cnt2 = 0;

	//if string start with 0
	for (int i = 0; i < str.size(); ++i) {
		if (i % 2 == 0) {
			if (str[i] != '0') cnt1++;
		}
		else {
			if (str[i] != '1') cnt1++;
		}
	}
	//if string start with 1
	for (int i = 0; i < str.size(); ++i) {
		if (i % 2 != 0) {
			if (str[i] != '0') cnt2++;
		}
		else {
			if (str[i] != '1') cnt2++;
		}
	}

	return cnt1 < cnt2 ? cnt1 : cnt2;
}

int main() {
	cout << minFlips("001") << endl;
	cout << minFlips("0001010111") << endl;

	return 0;
}