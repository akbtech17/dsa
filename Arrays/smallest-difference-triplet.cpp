// smallest - difference - triplet.cpp
#include <iostream>
#include <algorithm>
#include <climits>
#define MX 105
using namespace std;

bool comp(int a, int b) {
	return a > b;
}

void printSmallestDifferenceTriplet(int* arr1, int* arr2, int* arr3, int n) {
	int ans  = INT_MAX;
	int triplet[3] = {0};
	int sum = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				int mx = max(arr1[i], max(arr2[j], arr3[k]));
				int mn = min(arr1[i], min(arr2[j], arr3[k]));
				int csum = 0;
				csum += arr1[i] + arr2[j] + arr3[k];
				if ((mx - mn) < ans) {
					ans = mx - mn;
					sum = csum;
					triplet[0] = arr1[i];
					triplet[1] = arr2[j];
					triplet[2] = arr3[k];
				}
				else if (((mx - mn) == ans) and (csum < sum)) {
					sum = csum;
					triplet[0] = arr1[i];
					triplet[1] = arr2[j];
					triplet[2] = arr3[k];
				}
			}
		}
	}

	sort(triplet, triplet + 3, comp);

	for (int i = 0; i < 3; ++i)
	{
		cout << triplet[i] << " ";
	}
	return;
}

int main() {
	int arr1[MX] = {0};
	int arr2[MX] = {0};
	int arr3[MX] = {0};
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr1[i];
	for (int i = 0; i < n; ++i) cin >> arr2[i];
	for (int i = 0; i < n; ++i) cin >> arr3[i];

	printSmallestDifferenceTriplet(arr1, arr2, arr3, n);

	return 0;
}