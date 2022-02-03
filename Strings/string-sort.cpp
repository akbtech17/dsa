// string - sort.cpp
#include <iostream>
#define MX 100
using namespace std;

int strlen(char* str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

bool isStrPrefix(char* a, char* b) {
	int la = strlen(a);
	int lb = strlen(b);

	if (la > lb) return false;

	for (int i = 0; i < la; ++i) {
		if (a[i] != b[i]) return false;
	}

	return true;
}

bool isSwapRequired(char* a, char* b) {
	if (isStrPrefix(a, b)) return true;

	int la = strlen(a);
	int lb = strlen(b);

	int i = 0;
	int j = 0;

	while (i < la and j < lb) {
		if (a[i] == b[j]) {
			i++;
			j++;
		}
		else if (a[i] > b[j]) return true;
		else return false;
	}

	if (j == lb and i < la) return true;
	return false;
}

void swapStr(char str[][MX], int one, int two) {
	char temp[MX];
	int i = 0;
	for (; str[one][i] != '\0'; i++) temp[i] = str[one][i];
	temp[i] = '\0';
	i = 0;
	for (; str[two][i] != '\0'; ++i) str[one][i] = str[two][i];
	str[one][i] = '\0';
	i = 0;
	for (; temp[i] != '\0'; i++) str[two][i] = temp[i];
	str[two][i] = '\0';
	return;
}

void sortStrings(char str[][MX], int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (isSwapRequired(str[j], str[j + 1])) {
				swapStr(str, j, j + 1);
			}
		}
	}
	return;
}

int main() {
	//creating array of strings
	char str[1005][MX];
	int n;
	cin >> n;
	getchar();
	//input array of strings
	for (int i = 0; i < n; ++i) {
		cin.getline(str[i], MX);
	}
	sortStrings(str, n);
	//output array of strings
	for (int i = 0; i < n; ++i) {
		cout << str[i] << endl;
	}
	return 0;
}