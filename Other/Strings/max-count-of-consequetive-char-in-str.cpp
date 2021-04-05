// max - count - of - consequetive - char - in - str.cpp
#include <iostream>
#define MX 10000
using namespace std;

void maxConsChar(char *str, int len) {
	int mx_count = 0;
	char mx_char;

	for (int i = 0; i < len; ++i)
	{
		int curr_len = 1;
		// cout << str[i];
		while (i + 1 < len and str[i + 1] == str[i]) {
			curr_len++;
			i++;
		}
		// cout << curr_len;

		if (curr_len > mx_count) {
			mx_count = curr_len;
			if (i > 0)mx_char = str[i - 1];
			else mx_char = str[i];
		}
	}

	cout << mx_count << mx_char;
	return;
}


int main() {
	char str[MX];
	cin.getline(str, MX);
	int len = 0;
	while (str[len] != '\0') len++;
	maxConsChar(str, len);
	// cout << str;
	return 0;
}