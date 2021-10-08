// magic - number - 1.cpp
#include <iostream>
using namespace std;

//1st magic number = 7^0
//2nd magic number = 7^0+7^1
//3rd magic number = 7^0+7^1+7^2
//4th magic number = 7^0+7^1+7^2+7^3
int nthMagicNumber(int n) {
	//its like simple computation of GP
	int x = 1;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += x;
		x *= 7;
	}
	return ans;
}

int main() {

	for (int i = 1; i <= 5; ++i)
		cout << i << " magic number is : " << nthMagicNumber(i) << endl;

	return 0;
}