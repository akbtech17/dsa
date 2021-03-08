// longest - even - length - substring.cpp

// Given a string ‘str’ of digits,
// find the length of the longest substring of ‘str’,
// such that the length of the substring is 2k digits and sum
// of left k digits is equal to the sum of right k digits.

#include <iostream>
#define MX 1000
using namespace std;

int strLen(char* str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

void copyStrToArr(char* str, int* arr, int n) {
	for (int i = n - 1; i >= 0; --i)
		arr[i] = str[i] - '0';
	return;
}

int longestEvenSubstring(int* arr, int n) {
	if (n == 0) return 0;
	int csum[MX] = {0};
	csum[0] = arr[0];

	for (int i = 1; i < n; ++i)

		csum[i] = csum[i - 1] + arr[i];


	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; j += 2)
		{
			int mid = ((i + j) / 2) + 1;

			int right_sum = csum[j] - csum[mid - 1];

			int left_sum = csum[mid - 1];
			if (i > 0) left_sum -= csum[i - 1];

			if (right_sum == left_sum) {
				ans = max(j - i + 1, ans);
			}
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	char str[MX];
	int arr[MX] = {0};
	getchar();
	while (t--) {
		cin.getline(str, MX);
		int len = strLen(str);
		copyStrToArr(str, arr, len);
		cout << longestEvenSubstring(arr, len) << endl;
	}
	return 0;
}