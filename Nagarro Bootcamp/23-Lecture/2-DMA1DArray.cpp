// 2 - DMA1DArray.cpp
// 1 - Dma.cpp
#include <iostream>
using namespace std;

int main() {
	// int arr[100]; sma

	// dma
	int n;
	cin >> n;
	// int *arr = new int[5];
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << *(arr + i) << " ";
	}

	//deleting dma array
	delete []arr;
	arr = NULL;

	return 0;
}