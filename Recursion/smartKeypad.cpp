// smartKeypad.cpp
#include <iostream>
#include <string>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void printCodes(string str, int i = 0, string ans = "") {
	if ( i == str.length()) {
		cout << ans << endl;
		return;
	}
	int curr_dig = str[i] - '0';
	string temp = table[curr_dig];
	for (int j = 0; j < temp.length(); ++j) {
		printCodes(str, i + 1, ans + temp[j]);
	}
	return ;
}

int main() {
	string str;
	cin >> str;
	printCodes(str);

	return 0;
}