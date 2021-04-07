// 4 - KthSmallestLargest.cpp
// given that all array elements are distinct.
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


//Approach1
//tc nlogn
//sc const
void findKthSmallest(int arr[], int n, int k) {
	//sort the arr
	sort(arr, arr + n);

	//extract the kth first or last element
	cout << k << "th smallest element is " << arr[k - 1] << endl;
	// cout << k << "th largest element is " << arr[n - k] << endl;

	return;
}

//Approach2 - Using Min Heap – HeapSelect
//tc O(n + kLogn)
//sc linear
void findKthSmallest2(int arr[], int n , int k) {
	//init min heap wiht all n elements
	priority_queue<int, vector<int>, greater<int>> mn;
	for (int i = 0; i < n; i++) mn.push(arr[i]);
	//extract min element k times
	int ans;
	for (int i = 0; i < k; i++) {
		ans = mn.top();
		mn.pop();
	}
	cout << k << "th smallest element is " << ans << endl;
	return;
}

//Approach3 - QuickSelect
//tc worst n square avg linear
//sc const
int partition(int arr[], int pivot, int s, int e) {
	int i, j;
	i = j = s;
	while (i <= e) {
		if (arr[i] <= pivot) {
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
		else i++;
	}
	return j - 1; // pivot index
}


void findKthSmallestQuickSelect(int arr[], int s, int e , int k) {
	int pivot = arr[e]; //inital pivot
	int pi = partition(arr, pivot, s, e);

	if (k - 1 == pi) {
		//we got our ans
		cout << k << "th smallest element is " << arr[pi] << endl;
		return;
	}
	else if (k - 1 > pi) {
		//toh ans right me pada hoga
		findKthSmallestQuickSelect(arr, pi + 1, e, k);
	}
	else if (k - 1 < pi) {
		//ans left me pada hoga
		findKthSmallestQuickSelect(arr, s, pi - 1, k);
	}
	return;
}

int main() {
	int arr[] = {7, 10, 4, 3, 20, 15} ;
	int n = sizeof(arr) / sizeof(int);
	int k1 = 3;
	int k2 = 4;
	findKthSmallest(arr, n, k1);
	findKthSmallest(arr, n, k2);
	findKthSmallest2(arr, n, k1);
	findKthSmallest2(arr, n, k2);
	findKthSmallestQuickSelect(arr, 0, n - 1, k1);
	findKthSmallestQuickSelect(arr, 0, n - 1, k2);
	return 0;
}