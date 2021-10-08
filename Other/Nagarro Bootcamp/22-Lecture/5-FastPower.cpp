// 29FastPower.cpp
#include <iostream>
using namespace std;

int fastPower(int n, int x) {
	if (x == 0) return 1;
	int small_ans = fastPower(n, x / 2);
	if (x % 2 == 0) return small_ans * small_ans;
	return n * small_ans * small_ans;
}

int main() {
	cout << fastPower(5, 3);
	return 0;
}