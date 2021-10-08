// 2KeypadCodes.cpp
// https://hack.codingblocks.com/app/practice/1/1375/problem

#include <iostream>
#include <string>
using namespace std;
string keypad[] = {"", "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wx ", "yz"};

int countTheCodes(string str, int i = 0) {
	//base case
	if (i == str.size())
		return 1;

	int curr_dig = str[i] - '0';
	string curr_keypad_str = keypad[curr_dig];

	int count = 0;
	//iterate the keypad string
	for (int itr = 0; itr < curr_keypad_str.size(); ++itr) {
		count += countTheCodes(str, i + 1);
	}
	return count;
}

void printCodes(string str, int i = 0, string ans = "") {
	//base case
	if (i == str.size()) {
		//print ans
		cout << ans << " ";
		return ;
	}
	int curr_dig = str[i] - '0';
	string curr_keypad_str = keypad[curr_dig];

	//iterate the keypad string
	for (int itr = 0; itr < curr_keypad_str.size(); ++itr) {
		printCodes(str, i + 1, ans + curr_keypad_str[itr]);
	}
	return;
}

int main() {
	string str = "12";
	cin >> str;
	printCodes(str);
	cout << endl << countTheCodes(str);
	return 0;
}