// 4CountTrailingZeroes.cpp
#include <iostream>
using namespace std;

int CountTrailingZeroes(int num) {
	int cnt = 0;
	int div = 5;
	while ((num / div) != 0) {
		cnt += num / div;
		num /= div;
	}
	return cnt;
}

int main() {
	// int num = 20;
	// cout<<CountTrailingZeroes(num);
	cout << CountTrailingZeroes(5) << endl;
	cout << CountTrailingZeroes(20) << endl;
	cout << CountTrailingZeroes(100) << endl;

	return 0;
}