// splitArray.cpp
#include <iostream>
#define MX 100
#define ll long long
using namespace std;

int countWaysToSplit(int * arr, int n, ll sum1 = 0, ll sum2 = 0) {
	if ( n == 0) {
		if (sum1 == sum2) return 1;
		return 0;
	}
	int cnt = 0;
	//include in array1
	cnt +=  countWaysToSplit(arr, n - 1, sum1 + arr[n - 1], sum2);
	// include in array2
	cnt += countWaysToSplit(arr, n - 1, sum1, sum2 + arr[n - 1]);
	return cnt;
}

void printWays(int * arr, int n, int* temp, ll sum1 = 0, ll sum2 = 0) {
	if ( n == 0) {
		if (sum1 == sum2) {
			//print
			for (int i = 0; i < n; ++i) {
				if (temp[i] == 0) cout << arr[i] << " ";
			}
			cout << "and ";
			for (int i = 0; i < n; ++i) {
				if (temp[i] == 1) cout << arr[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	temp[n - 1] = 0;
	printWays(arr, n - 1, temp, sum1 + arr[n - 1], sum2);
	temp[n - 1] = 1;
	printWays(arr, n - 1, temp, sum1, sum2 + arr[n - 1]);
	return ;
}


int main() {
	int n;
	cin >> n;
	int arr[MX];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int temp[MX] = {0};
	cout << countWaysToSplit(arr, n);
	printWays(arr, n, temp);
	return 0;
}