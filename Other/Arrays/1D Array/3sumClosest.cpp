// 3sumClosest.cpp#include <iostream>
#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#define MX 10000
using namespace std;

//approach 2 - 2pointer
//tc n square
//sc const
int findClosestSum(int arr[], int n, int target) {
	int ans_diff = INT_MAX;
	int ans_sum;
	sort(arr, arr + n);

	for (int i = 0; i < n - 2; ++i) {
		int s = i + 1;
		int e = n - 1;

		while (s < e) {
			int csum = arr[i] + arr[s] + arr[e];

			int abs_diff = abs(target - csum);

			// cout << arr[i] << " " << arr[s] << " " << arr[e] << ":" << abs_diff << endl;
			// ans_diff = min(ans_diff, abs_diff);
			if (abs_diff < ans_diff) {
				ans_diff = abs_diff;
				ans_sum = csum;
			}
			if (csum <= target) {
				s++;
			}
			// else if (arr[i] + arr[s] + arr[e] < target) s++;
			else e--;
		}
	}
	return ans_sum;
}

int  main() {
	int n;
	cin >> n;
	int arr[MX] = {0};
	int target;
	cin >> target;
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << findClosestSum(arr, n, target);
	return 0;
}