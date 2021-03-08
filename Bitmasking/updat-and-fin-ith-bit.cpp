// try.cpp
#include <iostream>
using namespace std;

int findIthBit(int num, int i) {
	int mask = 1;
	mask = (mask << i);
	return (num & mask) != 0 ? 1 : 0;
}

void setIthBit(int &num, int i) {
	int mask = 1;
	mask = (mask << i);
	num = (num | mask);
	return ;
}

int main() {
	int num = 5;
	int ith = 1;
	setIthBit(num, ith);
	for (int i = 0; i < 10; ++i) cout << findIthBit(num, 9 - i);
	return 0;
}
