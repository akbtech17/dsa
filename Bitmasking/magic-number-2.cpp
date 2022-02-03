// magic - number - 2.cpp
#include <iostream>
#include <cmath>
using namespace std;

//1st magic number = 7^0
//2nd magic number = 7^1
//3rd magic number = 7^0+7^1
//4th magic number = 7^2
int nthMagicNumber(int n) {
	//iextracting the bits of n
	int i = 0;
	int ans = 0;
	while (n != 0) {
		if (n & 1 != 0) ans += pow(7, i);
		i++;
		n =  n >> 1;
	}
	return ans;
}

int main() {

	for (int i = 1; i <= 5; ++i)
		cout << i << " magic number is : " << nthMagicNumber(i) << endl;

	return 0;
}