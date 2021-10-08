// 6 - GenerateAllNDigitNumber.cpp
#include <iostream>
using namespace std;

void generateIncreasingDigitNumber(int n, string ans , int start) {
	if (n == 0) {
		// if (ans.size() != 0 )
		cout << ans << endl;
		return;
	}

	for (int i = start; i <= 9; i++) {
		char ch = '0' + i;
		ans += ch;
		generateIncreasingDigitNumber(n - 1, ans, i + 1);
		//remove the ch - backtrack
		ans.pop_back();
	}
	return;
}

int main() {
	int  n = 2;
	generateIncreasingDigitNumber(n, "", 0);
	return 0;
}