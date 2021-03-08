// max - frequency - character.cpp
#include <iostream>
#define MX 100000
using namespace std;

char maxFreChar(char* str) {
	char ans;
	char count = 0;

	int fre[26] = {0};

	for (int i = 0; str[i] != '\0'; ++i) {
		fre[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; ++i) {
		if (fre[i] > count) {
			count = fre[i];
			ans = 'a' + i;
		}
	}

	return ans;
}

int main() {
	char str[MX];
	cin.getline(str, MX);
	char ans = maxFreChar(str);
	cout << ans;
	return 0;
}