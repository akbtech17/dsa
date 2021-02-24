// playing - with - good - str.cpp
#include <iostream>
#include <ctype.h>
#define MX 100000
using namespace std;

int lenStr(char* str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

bool isGoodChar(char ch) {
	if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
		return true;
	return false;
}

int longesGoodStr(char* str) {
	int ans = 0;
	int n = lenStr(str);


	int curr_cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (isGoodChar(str[i])) {
			curr_cnt++;
			ans = max(curr_cnt, ans);
		}
		else {
			curr_cnt = 0;
		}
	}

	return ans;
}

int main() {
	char str[MX];
	cin.getline(str, MX);
	for (int i = 0; str[i] != '\0'; ++i) {
		str[i] = tolower(str[i]);
	}
	cout << longesGoodStr(str);
	// cout << str;
	return 0;
}