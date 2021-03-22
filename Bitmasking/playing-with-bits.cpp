// playing - with - bits.cpp
#include <iostream>
using namespace std;


int bitsSet(int num) {
	int count = 0;
	while (num > 0) {
		num = (num & (num - 1));
		count++;
	}
	return count;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int s, e;
		cin >> s >> e;
		int ans = 0;
		for (int i = s; i <= e; ++i)
			ans += bitsSet(i);
		cout << ans << endl;
	}

	return 0;
}