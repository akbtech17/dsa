// tryy.cpp
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int findDiff(int a, int b , int c) {
	int mx;
	int mn;

	mx = max(a, max(b, c));
	mn = min(a, min(b, c));

	return mx - mn;
}

void printMinDifferenceTriplet(int* arr1, int* arr2, int* arr3, int n) {
	int ans_diff = INT_MAX;
	vector<int> ans;
	int ans_sum;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				int curr_diff = findDiff(arr1[i], arr2[j], arr3[k]);
				int curr_sum = arr1[i] + arr2[j] + arr3[k];
				if (curr_diff < ans_diff) {
					ans.clear();
					ans.push_back(arr1[i]);
					ans.push_back(arr2[j]);
					ans.push_back(arr3[k]);
					ans_diff = curr_diff;
					ans_sum = curr_sum;
				}
				else if (curr_diff == ans_diff and curr_sum < ans_sum) {
					ans.clear();
					ans.push_back(arr1[i]);
					ans.push_back(arr2[j]);
					ans.push_back(arr3[k]);
					ans_diff = curr_diff;
					ans_sum = curr_sum;
				}
			}
		}
	}
	sort(ans.begin(), ans.end(), compare);
	for (auto el : ans) cout << el << " ";
	return;
}

int main() {
	int n;
	cin >> n;
	int arr1[100], arr2[100], arr3[100];
	for (int i = 0; i < n; i++) cin >> arr1[i];
	for (int i = 0; i < n; i++) cin >> arr2[i];
	for (int i = 0; i < n; i++) cin >> arr3[i];

	printMinDifferenceTriplet(arr1, arr2, arr3, n);

	return 0;
}