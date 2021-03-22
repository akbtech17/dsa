// unique - number - 3.cpp
#include <iostream>
#include <cmath>
using namespace std;

int findUniqueNumber(int *arr, int n) {
	int ans = 0;

	int bitmap[64] = {0};

	for (int i = 0; i < n; ++i)
	{
		int pos = 0;
		while (arr[i] > 0) {
			bitmap[pos] += (arr[i] & 1) > 0 ? 1 : 0;
			arr[i] >>= 1;
			pos++;
		}
	}

	for (int i = 0; i < 64; ++i) {
		bitmap[i] = bitmap[i] % 3;
		ans += bitmap[i] * pow(2, i);
	}

	return ans;
}

int main() {
	int n;
	cin >> n;
	int arr[100000] = {0};
	for (int i = 0 ; i < n ; i++) cin >> arr[i];

	cout << findUniqueNumber(arr, n);
	return 0;
}