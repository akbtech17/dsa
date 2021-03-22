// MSS - 1.cpp
#include <iostream>
using namespace std;

//tc n cube
//sc 1
void msm1(int *arr, int n) {
	int msum = 0;
	int l = -1;
	int r = -1;

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int csum  = 0;
			for (int k = i; k <= j; ++k)
				csum += arr[k];
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

	msm1(arr, n);

	return 0;
}