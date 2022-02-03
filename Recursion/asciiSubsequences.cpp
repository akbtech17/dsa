// asciiSubsequences.cpp
#include <iostream>
#include <string>
using namespace std;

int ans_num = 0 ;
void printASCIISubsequences(string str, int i = 0, string ans = "") {
	if (i == str.length()) {
		cout << ans << " ";
		ans_num++;
		return;
	}
	//1-add nothing
	printASCIISubsequences(str, i + 1, ans);
	//2-add curr char
	printASCIISubsequences(str, i + 1, ans + str[i]);
	//3-add ascci of curr char
	int asc = str[i];
	string as = to_string(asc);
	ans.append(as);
	printASCIISubsequences(str, i + 1, ans);
	return ;
}

int main() {
	string s;
	cin >> s;
	printASCIISubsequences(s);
	cout << endl << ans_num;
	return 0;
}