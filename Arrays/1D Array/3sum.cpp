// 3sum.cpp

#include <iostream>
#include <algorithm>
#define MX 1005
using namespace std;


//approach 1 - bruteforce
//tc n cube
//sc const
void printAllTriplets(int arr[], int n, int target) {
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (arr[i] + arr[j] + arr[k] == target) {
					cout << arr[i] << ", " << arr[j] << " and " << arr[k] << endl;
				}
			}

		}
	}
	return;
}

//approach 2 - 2pointer
//tc n square
//sc const
void printAllTriplets2(int arr[], int n, int target) {
	sort(arr, arr + n);

	for (int i = 0; i < n - 2; ++i) {
		int s = i + 1;
		int e = n - 1;

		while (s < e) {
			if (arr[i] + arr[s] + arr[e] == target) {
				cout << arr[i] << ", " << arr[s] << " and " << arr[e] << endl;
				s++;
			}
			else if (arr[i] + arr[s] + arr[e] < target) s++;
			else e--;
		}
	}
	return;
}

int  main() {
	int n;
	cin >> n;
	int arr[MX] = {0};
	for (int i = 0; i < n; i++) cin >> arr[i];
	int target;
	cin >> target;
	// printAllTriplets(arr, n, target);
	printAllTriplets2(arr, n, target);
	return 0;
}