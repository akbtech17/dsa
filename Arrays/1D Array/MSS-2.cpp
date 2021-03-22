// MSM - 2.cpp
#include <iostream>
using namespace std;

//tc n square
//sc n
void msm2(int *arr, int n) {
	int msum = 0;
	int l = -1;
	int r = -1;

	int pre[n] = {0};
	pre[0] = arr[0];
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + arr[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int csum = pre[j];
			if (i > 0) csum -= pre[i - 1];

			if (csum > msum) {
				msum = csum;
				l = i;
				r = j;
			}
		}
	}

	cout << "Max Subarray Sum is : " << msum << "\nAt : ";
	cout << l << " " << r;
}


int main() {
	int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr) / sizeof(int);

	msm2(arr, n);

	return 0;
}