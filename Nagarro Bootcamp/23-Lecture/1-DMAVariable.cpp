// 1 - Dma.cpp
#include <iostream>
using namespace std;

int main() {
	// int y = 10; sma
	// dma
	int *x = new int;
	*x = 10;

	cout << "address of x : " << x << endl;
	cout << "vaule of x : " << *x << endl;

	// float y  = 20.8; sma
	// dma
	float *y = new float;
	*y = 20.8;

	cout << "address of y : " << y << endl;
	cout << "vaule of y : " << *y << endl;

	//deleting dma var
	delete x;
	delete y;
	x = NULL;
	y = NULL;

	return 0;
}