// 1CountTheNumberOfTriangles.cpp
#include <iostream>
#include <algorithm>
using namespace std;


int CountTheNumberOfTriangles(int arr[], int n) {
	if (n < 3) return 0;
	// the sum of any of the two values (or sides)
	// must be greater than the third value (or third side)
	sort(arr, arr + n);
	int count = 0;
	//fix the last index
	for (int last_idx = n - 1; last_idx >= 1; last_idx--) {
		int s = 0;
		int e = last_idx - 1;
		while (s < e) {
			if (arr[s] + arr[e] > arr[last_idx]) {
				count += e - s ;
				e--;
			}
			else {
				s++;
			}
		}
	}
	return count;
}

int main() {
	// int arr1[] = {4, 6, 3, 7};
	// int n1 = sizeof(arr1) / sizeof(int);
	// int arr2[] = {10, 21, 22, 100, 101, 200, 300};
	// int n2 = sizeof(arr2) / sizeof(int);

	// cout << CountTheNumberOfTriangles(arr1, n1) << endl;
	// cout << CountTheNumberOfTriangles(arr2, n2) << endl;

	int arr[10005] = {0};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << CountTheNumberOfTriangles(arr, n);
	return 0;
}