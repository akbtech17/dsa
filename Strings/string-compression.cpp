// string - compression.cpp

// Take as input S, a string.
// Write a function that does basic string compression.
// Print the value returned.
// E.g. for input “aaabbccds”
// print out a3b2c2d1s1.

#include <iostream>
#define MX 10000
using namespace std;

void printCompressedString(char* str) {
	for (int itr = 0; str[itr] != '\0'; itr++) {
		//mark the count
		int count = 1;
		//print the curr character
		cout << str[itr];
		while (str[itr + 1] != '\0' and str[itr] == str[itr + 1])
			count++, itr++;
		//print the count
		cout << count;
	}
}

//function to convert num into string
char* numToStr(int num) {
	char* str;
	str = (char*)malloc(MX);
	int i = 0;
	while (num) {
		char digit = '0' + (num % 10);
		num /= 10;
		str[i] = digit;
		i++;
	}
	str[i] = '\0';

	int s = 0;
	int e = i - 1;
	while (s <= e) {
		swap(str[s++], str[e--]);
	}
	// cout << str;
	return str;
}

//return the compressed string
char* compressTheString(char* str) {
	char ch = str[0];
	int itr = 0;
	char *ans;
	ans = (char*)malloc(MX);
	int j = 0;
	while (str[itr] != '\0') {
		ans[j++] = str[itr];
		int cnt = 1;
		while (str[itr + 1] != '\0' and str[itr] == str[itr + 1]) cnt++, itr++;
		char* countStr = numToStr(cnt);
		cout << countStr;
		int k = 0;
		while (countStr[k] != '\0') ans[j++] = countStr[k++];
	}
	ans[j] = '\0';
	cout << ans;
	return (char*)ans;
}

int main() {
	char str[MX];
	cin.getline(str, MX);
	// printCompressedString(str);
	cout << compressTheString(str);

	return 0;
}