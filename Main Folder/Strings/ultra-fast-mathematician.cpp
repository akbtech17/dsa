// ultra - fast - mathematician.cpp
#include <iostream>
#define MX 100000
using namespace std;

//perform xor of two strings

int strlen(char* str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

char* performMath(char* str1, char* str2) {
	char* ans;
	int n = strlen(str1);
	ans = (char*)malloc(n + 1);
	for (int i = 0; i < n; i++) {
		if (str1[i] == str2[i])
			ans[i] = '0';
		else ans[i] = '1';
	}
	ans[n] = '\0';
	return ans;
}

int main() {
	int t;
	cin >> t;
	getchar();
	while (t--) {
		char str1[MX], str2[MX];
		cin.getline(str1, MX, ' ');
		cin.getline(str2, MX);
		char* ans = performMath(str1, str2);
		cout << ans << endl;
	}
	return 0;
}