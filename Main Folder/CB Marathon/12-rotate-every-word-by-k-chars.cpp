
#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int fre[26] = {0};
	for (auto el : str) {
		fre[el - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (fre[i] > 1) ans += fre[i] - 1;
	}
	cout << ans;

	return 0;
}
