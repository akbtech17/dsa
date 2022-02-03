// subarrays - again.cpp
// 2
// 4
// 4 2 1 3
// 5
// 5 4 3 2 1

#include <iostream>
#include <stack>
#define MX 100000
using namespace std;

void nextGreaterInRight(int *arr, int n) {
	int ngr[n] = {0};
	stack<int> stk;

	stk.push(arr[0]);
	ngr[n - 1] = n;
	for (int i = n - 2; i >= 0; --i) {
		//make ans;
		if (stk.empty()) {
			ngr[i] = n;
		}
		else {
			while (!stk.empty() and stk.top() <= arr[i]) stk.pop();
			if (stk.empty()) ngr[i] = n;
			else ngr[i] = stk.top();
		}

		//push curr el
		stk.push(arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ":";
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << ngr[i] << ":";
	}
	cout << endl;

	return ;
}

int maxLengthSubarray(int *arr, int n) {
	int ans = 0;
	nextGreaterInRight(arr, n);
	//generate all possible subarrays
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {

			int len = j - i + 1;
			if (arr[i] >= arr[j] and len > ans) {
				ans = len;
			}

		}
	}

	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[MX] = {0};
		for (int i = 0; i < n; i++) cin >> arr[i];

		cout << maxLengthSubarray(arr, n) << endl;
	}

	return 0;
}