// sanket - and - strings.cpp
#include <iostream>
#define MX 100000
using namespace std;

int strLen(char* str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}


int maxLengthSubstringOfSameChar(char* str, int k) {
	int n = strLen(str);

	int a_cnt[MX] = {0};
	int b_cnt[MX] = {0};

	for (int i = 0; i < n; ++i)
	{
		char curr = str[i];
		if (curr == 'a') {
			if (i == 0) a_cnt[i] = 1;
			else {
				a_cnt[i] = 1 + a_cnt[i - 1];
				b_cnt[i] = b_cnt[i - 1];
			}
		}
		else {
			if (i == 0) b_cnt[i] = 1;
			else {
				b_cnt[i] = 1 + b_cnt[i - 1];
				a_cnt[i] = a_cnt[i - 1];
			}

		}
	}

	// for (int i = 0; i < n; ++i) cout << a_cnt[i];
	// cout << endl;
	// for (int i = 0; i < n; ++i) cout << b_cnt[i];
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			int a = a_cnt[j];
			if (i > 0) a -= a_cnt[i - 1];
			int b = b_cnt[j];
			if (i > 0) a -= b_cnt[i - 1];

			// cout << i << ":" << j << ":" << a << ":" << b << endl;

			if (a <= k or b <= k) {
				ans = max(ans, j - i + 1);
			}
		}
	}

	return ans;
}

int main() {
	char str[MX];
	int k;
	cin >> k;
	getchar();
	cin.getline(str, MX);

	cout << maxLengthSubstringOfSameChar(str, k);

	return 0;
}