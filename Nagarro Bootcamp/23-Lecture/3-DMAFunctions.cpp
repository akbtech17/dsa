// 3 - DMAFunctions.cpp
#include <iostream>
using namespace std;


int* f(int n) {
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
	}
	return arr;
	//delete arr
	cout << "derleting arr from function";
	delete []arr;
}

int main() {

	int n;
	cin >> n;
	int *arr = f(n);

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << *(arr + i) << " ";
	}
	//deleting dma array
	delete []arr;
	arr = NULL;

	return 0;
}