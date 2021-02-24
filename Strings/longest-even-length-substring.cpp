// longest - even - length - substring.cpp
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
	{
		arr[i] = str[i] - '0';
	}
	return;
}

int longestEvenSubstring(int* arr, int n) {
	if (n == 0) return 0;
	int csum[MX] = {0};
	csum[0] = arr[0];

	for (int i = 1; i < n; ++i)
	{
		csum[i] = csum[i - 1] + arr[i];
	}

	int ans = 0;
	// int i_idx = -1;
	// int j_idx = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; j += 2)
		{
			int mid = ((i + j) / 2) + 1;

			int right_sum = csum[j] - csum[mid - 1];

			int left_sum = csum[mid - 1];
			if (i > 0) left_sum -= csum[i - 1];

			if (right_sum == left_sum) {
				// cout << i << ":" << j << ":" << left_sum << ":" << right_sum << endl;
				if ((j - i + 1) > ans) {
					// i_idx = i;
					// j_idx = j;
				}
				ans = max(j - i + 1, ans);

			}
		}
	}

	// for (int i = i_idx; i <= j_idx; ++i)
	// {
	// 	cout << arr[i];
	// }
	// cout << endl;
	return ans;
}

int main() {
	// int t;
	// cin >> t;
	// cout << t;
	// for (int i = 0; i < t; i++) {

	// }
	int testcase;
	cin >> testcase;
	char str[MX];
	int arr[MX] = {0};
	bool itsFirst = true;
	while (testcase--) {
		if (itsFirst) {
			getchar();
			itsFirst = false;
		}
		cin.getline(str, MX);
		int len = strLen(str);
		copyStrToArr(str, arr, len);
		cout << longestEvenSubstring(arr, len) << endl;
	}
	return 0;
}