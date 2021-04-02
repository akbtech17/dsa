// 30SplitArray.cpp
// https://hack.codingblocks.com/app/practice/1/250/problem
#include <iostream>
#define ll long long
#define MX 100000
using namespace std;

int countArr(int arr[], int n, ll sum1 = 0, ll sum2 = 0) {
	if (n == 0) {
		if (sum1 == sum2) {
			return 1;
		}
		return 0;
	}

	return countArr(arr + 1, n - 1, sum1 + arr[0], sum2) + countArr(arr + 1, n - 1, sum1, sum2 + arr[0]);

}

void PrintSplitArray(int arr[], int n, int a1[], int a2[], ll sum1 = 0, ll sum2 = 0, int i = 0, int j = 0) {
	if (n == 0) {
		if (sum1 == sum2) {
			// cout << "sum : " << sum1 << " " << sum2 << " :: " ;
			//print arrays
			for (int k = 0; k < i; ++k) {
				cout << a1[k] << " ";
			}
			cout << " and ";
			for (int k = 0; k < j; ++k) {
				cout << a2[k] << " ";
			}
			cout << endl;
		}
		return;
	}
	a1[i++] = arr[0];
	PrintSplitArray(arr + 1, n - 1, a1, a2, sum1 + arr[0], sum2, i, j);
	a2[j++] = arr[0];
	PrintSplitArray(arr + 1, n - 1, a1, a2, sum1, sum2 + arr[0], i - 1, j);
	return;
}

int main() {
	// int n = 6;
	// int arr[] = {1, 2, 3, 3, 4, 5};
	int n;
	cin >> n;
	int arr[MX] = {0};
	for (int i = 0; i < n; i++) cin >> arr[i];
	int a1[MX] = {0};
	int a2[MX] = {0};

	PrintSplitArray(arr, n, a1, a2);
	cout << countArr(arr, n);

	return 0;
}