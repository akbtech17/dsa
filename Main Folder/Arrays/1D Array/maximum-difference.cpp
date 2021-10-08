// maximum - difference.cpp
#include <iostream>
#include <climits>
#define MX 100000
using namespace std;

// 7
// 2 3 10 6 4 8 1

int maximumDifference(int *arr, int n) {
	int max_diff_so_far = arr[1] - arr[0];
	int min_element_so_far = arr[0];


	for (int i = 1; i < n; ++i) {
		//find the cdiff
		if (arr[i] - min_element_so_far > max_diff_so_far) {
			max_diff_so_far = arr[i] - min_element_so_far;
			//update minele
			if (arr[i] < min_element_so_far)
				min_element_so_far = arr[i];
		}
	}
	return max_diff_so_far;
}

int main() {
	int n;
	cin >> n;
	int arr[n] = {0};
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << maximumDifference(arr, n);

	return 0;
}