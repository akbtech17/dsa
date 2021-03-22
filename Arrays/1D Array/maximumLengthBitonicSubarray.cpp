// maximumLengthBitonicSubarray.cpp
#include <iostream>
#include <climits>
using namespace std;

int maxLenBitonicSubarr(int *arr, int n) {
	int max_len_sor_far = 0;
	int s = 0;
	int i = 0;

	int *dec = (int*)malloc(sizeof(int) * n);
	int *inc = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			inc[i] = 1;
		}
		else {
			if (arr[i - 1] <= arr[i]) inc[i] = inc[i - 1] + 1;
			else inc[i] = 1;
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		if (i == n - 1) {
			dec[i] = 1;
		}
		else {
			if (arr[i + 1] <= arr[i]) dec[i] = dec[i + 1] + 1;
			else dec[i] = 1;
		}
	}
	int ans = INT_MIN;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, inc[i] + dec[i] - 1);
	}

	return ans;
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* arr = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << maxLenBitonicSubarr(arr, n) << endl;
		// for (int i = 0; i < n; ++i)
		// 	cout << arr[i] << " ";
		// cout << endl;
		delete[] arr;
	}
}