// merge - 2 - sorted - arrays.cpp
#include <iostream>
#define MX 100000
using namespace std;

// 4
// 6 7 8 9
// 3
// 1 5 10

void printArr(int* arr, int n) {
	for (int i = 0; i < n; ++i) cout << arr[i] << ":";
	cout << endl;
	return;
}

//TC - order of n1+n2
//SC - order of 1
void mergeTwoSortedArr(int *arr1, int n1, int *arr2, int n2) {
	//shifting all contents in arr1
	int i = n1 - 1;
	int j = n2 - 1;
	int k = n1 + n2 - 1;

	while (i >= 0 and j >= 0) {
		if (arr1[i] > arr2[j]) arr1[k--] = arr1[i--];
		else arr1[k--] = arr2[j--];
	}

	while (j >= 0) {
		arr1[k--] = arr2[j--];
	}

	printArr(arr1, n1 + n2 - 1);

	return;
}

//TC - order of n1+n2
//SC - order of n1+n2
void mergeTwoSortedArr2(int *arr1, int n1, int *arr2, int n2) {
	//shifting all contents in arr1
	int i = 0;
	int j = 0;
	int k = 0;

	int temp[MX] = {0};

	while (i < n1 and j < n2) {
		if (arr1[i] < arr2[j]) temp[k++] = arr1[i++];
		else temp[k++] = arr2[j++];
	}

	while (i < n1) {
		temp[k++] = arr1[i++];
	}

	while (j < n2) {
		temp[k++] = arr2[j++];
	}

	printArr(temp, k);

	return;
}

int main() {
	int n1 = 0, n2 = 0;
	int arr1[MX] = {0}, arr2[MX] = {0};

	cin >> n1;
	for (int i = 0; i < n1; i++) cin >> arr1[i];
	cin >> n2;
	for (int i = 0; i < n2; i++) cin >> arr2[i];

	// mergeTwoSortedArr(arr1, n1, arr2, n2);
	mergeTwoSortedArr2(arr1, n1, arr2, n2);

	return 0;

}