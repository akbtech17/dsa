// 13TowerOfHanoi.cpp
#include <iostream>
using namespace std;

int ans = 0;
void moveDisks(int n, char src, char dest, char helper) {
	if (n == 0 ) return;
	moveDisks(n - 1, src, helper, dest);
	cout << "Move " << n << "th disc from T" << src << " to T" << dest << endl;
	ans++;
	moveDisks(n - 1, helper, dest, src);
}

int main() {
	int n = 3;
	cin >> n;
	moveDisks(n, '1', '2', '3');
	cout << ans;
	return 0;
}