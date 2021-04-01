// maximum - circular - sum.cpp
#include <iostream>
#include <climits>
#define MX 1005
#define ll long long
using namespace std;

ll findMaxCSum(int *arr, int n) {
	ll max_sum = LLONG_MIN;
	ll presum[MX] = {0};

	for (int i = 0; i < n; ++i) {
		if (i == 0) presum[i] = arr[i];
		else presum[i] = presum[i - 1] + arr[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ll curr_sum = 0;
			if (i <= j) {
				curr_sum = presum[j] - presum[i - 1];
			}
			else {
				curr_sum = presum[n - 1] + presum[j] - presum[i - 1];
			}
			max_sum = max(max_sum, curr_sum);
		}
	}
	return max_sum;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[MX] = {0};
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << findMaxCSum(arr, n) << endl;
	}
	return 0;
}