// permutation.cpp
#include <iostream>
#define MX 10000
using namespace std;

bool isPermutation(char *str1, int len1, char *str2, int len2) {
	if (len1 != len2) return false;

	int fre[MX] = {0};

	for (int i = 0; i < len1; ++i) {
		fre[str1[i] - 'a']++;
	}

	for (int i = 0; i < len2; ++i) {
		fre[str2[i] - 'a']--;
	}

	for (int i = 0; i < len1; ++i)
	{
		if (fre[i] != 0) return false;
	}

	return true;
}


int main() {
	char str1[MX], str2[MX];
	cin.getline(str1, MX);
	cin.getline(str2, MX);
	int len1 = 0, len2 = 0;
	while (str1[len1] != '\0') len1++;
	while (str2[len2] != '\0') len2++;
	if (isPermutation(str1, len1, str2, len2)) cout << "true";
	else cout << "false";
	return 0;
}