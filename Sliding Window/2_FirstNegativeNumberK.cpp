// 2_FirstNegativeNumberK.cpp
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// TC - O(N)
// SC - O(K)

#include <iostream>
#include <queue>
using namespace std;

void findFirstNegativeK(int *arr, int n , int k) {
	int s = 0;
	int e = 0;
	queue<int> q;
	while (e < n) {
		//add calculations
		if (arr[e] < 0) {
			q.push(arr[e]);
		}
		//create window
		if (e - s + 1 < k) {
			e++;
		}
		//maintain window
		else if (e - s + 1 == k) {
			if (q.empty()) cout << 0 << " ";
			else cout << q.front() << " ";
			if (arr[s] == q.front()) {
				q.pop();
			}
			s++;
			e++;
		}
	}
	return;
}

int main() {
	int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28};
	int n = sizeof(arr) / sizeof(n);
	int k = 3;

	findFirstNegativeK(arr, n, k);

	return 0;
}