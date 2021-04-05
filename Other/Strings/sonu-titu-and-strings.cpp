// sonu - titu - and - strings.cpp

// Sonu and Titu have two Strings.
// They want to make their strings anagrams of each other.
// They can either delete a character from string of Titu
// and add a character to the string of Sonu.
// Find the minimum number of operations
// required to make the strings anagrams of each other.

#include <iostream>
#define MX 100000
using namespace std;

int strLen(char *str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

int minNumberToMakeAnagram(char* str1, char* str2) {
	int ans = 0;

	int n1 = strLen(str1);
	int n2 = strLen(str2);

	if (n1 == 0) return n2;
	if (n2 == 0) return n1;

	int fre[26] = {0};

	for (int i = 0; i < n1; ++i)
	{
		fre[str1[i] - 'a']++;
	}

	for (int i = 0; i < n2; ++i)
	{
		fre[str2[i] - 'a']--;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (fre[i] != 0)
		{
			if (fre[i] > 0)ans += fre[i];
			else ans += ((-1) * fre[i]);
		}
	}

	return ans;
}

int main() {
	int t;
	cin >> t;
	getchar();
	while (t--) {
		char str1[MX], str2[MX];
		cin.getline(str1, MX);
		cin.getline(str2, MX);
		cout << minNumberToMakeAnagram(str1, str2) << endl;
	}
	return 0;
}