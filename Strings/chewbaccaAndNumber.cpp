// chewbaccaAndNumber.cpp
#include <iostream>
#include <string>
using namespace std;

void convertString(string &str) {
	for (int i = 0; i < str.length(); ++i) {
		int curr_dig = str[i] - '0';
		if (i == 0 and curr_dig == 9) continue;
		else {
			if (9 - curr_dig < curr_dig) {
				str[i] = char('0' + 9 - curr_dig);
			}
		}
	}
	// cout << str;
	return;
}
int main() {
	string str;
	cin >> str;
	convertString(str);
	cout << str;
	return 0;
}