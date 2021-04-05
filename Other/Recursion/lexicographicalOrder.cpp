// lexicographicalOrder.cpp
#include <iostream>
#include <set>
using namespace std;

set<string> s;

void lexicoOrder(int num ) {
	if (num == -1) {
		return ;
	}
	string temp = to_string(num);
	s.insert(temp);
	lexicoOrder(num - 1);
	return;
}

int main() {
	int n;
	cin >> n;
	lexicoOrder(n);
	for (auto el : s) cout << el << " ";
	return 0;
}