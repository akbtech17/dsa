// count - palindromic - substring.cpp
#include <iostream>
#define MX 100000
using namespace std;

int strlen(char* str) {
	int i = 0 ;
	while (str[i] != '\0') i++;
	return i;
}

bool isPalindrome(char* str) {
	int s = 0;
	int e = strlen(str) - 1;

	while (s <= e) {
		if (str[s] != str[e]) return false;
		s++;
		e--;
	}

	return true;
}

int countPalindromicSubstring(char* str) {
	//generate substring
	int n = strlen(str);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			char temp[MX];
			int t = 0;
			for (int k = i; k <= j; ++k)
			{
				temp[t++] = str[k];
			}
			temp[t] = '\0';
			if (isPalindrome(temp)) ans++;
		}
	}
	return ans;
}

int main() {
	char str[MX];
	cin.getline(str, MX);

	cout << countPalindromicSubstring(str);

	return 0;
}