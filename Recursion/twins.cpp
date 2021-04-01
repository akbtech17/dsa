// twins.cpp
#include <iostream>
#include <string>
using namespace std;

int ans = 0;
void countTwins(string str, int i = 0) {
	//base case
	if ( i == str.length() - 2) return;
	if (i + 2 < str.length() and str[i] == str[i + 2] and str[i] != str[i + 1]) ans++;
	countTwins(str, i + 1);
	return;
}

int main() {
	string str;
	cin >> str;

	countTwins(str);


	cout << ans;
	return 0;
}