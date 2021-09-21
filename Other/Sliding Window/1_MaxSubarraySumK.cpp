// 1_MaxSubarraySumK.cpp
// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#

// TC - O(N)
// SC - O(1)

#include <iostream>
#include <climits>
using namespace std;

void findMaxSubarraySumK(int *arr, int n , int k) {
	int s = 0;
	int e = 0;
	int max_sum = INT_MIN;
	int curr_sum = 0;
	while (e < n) {
		//add calculations
		curr_sum += arr[e];
		//create window
		if (e - s + 1 < k) {
			e++;
		}
		//maintain window
		else if (e - s + 1 == k) {
			max_sum = max(max_sum, curr_sum);
			curr_sum -= arr[s++];
			e++;
		}
	}

	cout << max_sum;
	return;
}

int main() {
	int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
	int n = sizeof(arr) / sizeof(n);
	int k = 4;

	findMaxSubarraySumK(arr, n, k);

	return 0;
}