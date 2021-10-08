// 25RemoveDuplicates.cpp
#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string str, int i = 0) {
	if (i == str.size() - 1) return str.substr(i);
	string ans;
	string small_ans = removeDuplicates(str, i + 1);
	if (i + 1 < str.size() and str[i + 1] != str[i]) {
		ans += str[i];
		ans += small_ans;
		return ans;
	}
	return small_ans;
}

int main() {
	string str = "helleeo";
	cout << removeDuplicates(str);
	return 0;
}