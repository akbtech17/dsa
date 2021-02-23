// rotate - k - string.cpp
#include <iostream>
using namespace std;

void rotateKString(char* str, int len, int k) {
	//if empty string
	if (len == 0) return;
	//if k is greater than len
	k = k % len;

	//shift the char k blocks ahead, starting from the last char
	for (int i = len; i >= 0; i--)
	{
		str[i + k] = str[i];
	}

	//last char ko front me lao
	int i = 0;
	int j  = len;
	while (k--) {
		str[i] = str[j];
		i++; j++;
	}
	//insert null at last pos
	str[len]  = '\0';
	return ;
}


int main() {
	char str[1000];
	cin.getline(str, 1000);
	int k ;
	cin >> k;

	int len = 0;
	while (str[len] != '\0') len++;
	rotateKString(str, len, k);
	cout << str;
	return 0;
}