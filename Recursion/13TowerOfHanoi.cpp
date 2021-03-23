// 13TowerOfHanoi.cpp
#include <iostream>
using namespace std;

void moveDisks(int n, char src, char dest, char helper) {
	if (n == 0 ) return;
	moveDisks(n - 1, src, helper, dest);
	cout << "move " << n << "th disk from " << src << " to " << dest << endl;
	moveDisks(n - 1, helper, dest, src);
}

int main() {
	int n = 3;
	moveDisks(n, 'A', 'C', 'B');
	return 0;
}