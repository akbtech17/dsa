// swap - all - odd - even - bits.cpp
#include <iostream>
using namespace std;

unsigned int swapBits(unsigned int x) {

	unsigned int ebits = x & 0xAAAAAAAA;
	unsigned int obits = x & 0x55555555;

	ebits >>= 1;
	obits <<= 1;

	return (ebits | obits);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		unsigned int num;
		cin >> num;
		cout << swapBits(num) << endl;
	}
	return 0;
}