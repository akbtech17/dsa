// 4isSortedArray.cpp
#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
	if (n == 0) return true;

	if (arr[0] <= arr[1] and isSorted(arr + 1, n - 1))
		return true;
	return false;
}

int main() {
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {2, 1, 3, 4, 5};
	int n = 5;
	if (isSorted(arr1, n))
		cout << "Array 1 is Sorted";
	else cout << "Array 1 is NotSorted";
	cout << endl;
	if (isSorted(arr2, n))
		cout << "Array 2 is Sorted";
	else cout << "Array 2 is NotSorted";

	return 0;
}