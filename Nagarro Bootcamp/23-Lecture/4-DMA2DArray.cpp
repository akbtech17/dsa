// 4 - DMA2DArray.cpp
#include <iostream>
using namespace std;

int main() {
	// int arr[5][20]; sma

	// dma
	int row = 3;
	int col = 2;

	int **arr = new int* [row];
	for (int i = 0; i < row; ++i) {
		arr[i] = new int[col];
	}

	// init array
	int num = 1;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			arr[i][j] = num++;
		}
	}

	//printing array
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


	//deleting dma 2d array
	for (int i = 0; i < row; ++i) {
		delete []arr[i];
	}

	delete []arr;
	arr = NULL;

	return 0;
}