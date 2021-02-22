#include <iostream>
#include <algorithm>
using namespace std;

//Order of N cube
int bruteforce(int* arr, int n) {
	if (n < 3) return 0;
	int ans = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				if (arr[k] < arr[i] + arr[j]) {
					ans++;
				}
			}
		}
	}
	return ans;
}

//Order of N Square
int optimized1(int* arr, int n) {
	if (n < 3) return 0;

	int last_idx = n - 1;
	int ans = 0;
	sort(arr, arr + n);

	while (last_idx >= 1) {
		int left_idx = 0;
		int right_idx = last_idx - 1;

		while (left_idx < right_idx) {
			if (arr[left_idx] + arr[right_idx] > arr[last_idx]) {
				ans += (right_idx - left_idx);
				right_idx--;
			}
			else {
				left_idx++;
			}
		}
		last_idx--;
	}
	return ans;
}

int main() {
	int n, arr[10005];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	// cout << bruteforce(arr, n);
	cout << optimized1(arr, n);
}