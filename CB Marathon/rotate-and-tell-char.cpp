// rotate - and - tell - char.cpp
#include <iostream>
using namespace std;

// 6
// a 2
// p 1
// c 3
// p 3
// a 4
// p 1

void printStringAfterRotation(string str, int n, int net_rotaiton) {
	for (int i = 0; i < str.length(); ++i) {
		int apos = (i + net_rotaiton + n) % n;
		cout << str[apos];
	}
	cout << endl;
	return;
}

void anticlockwiseRotate(int &net_rotaiton, int units, int n) {
	//right shift
	net_rotaiton = (net_rotaiton - units) % n;
	return;
}



void clockwiseRotate(int &net_rotaiton, int units, int n) {
	//left shift
	net_rotaiton = (net_rotaiton + units) % n;
	return;
}

char tellChar(string str, int n, int net_rotaiton, int pos) {
	//actual position
	int apos = (net_rotaiton + (pos - 1) + n) % n;
	return str[apos];
}

int main() {
	string str = "abcde";
	int net_rotaiton = 0;
	int n = str.length();
	int q;
	cin >> q;
	while (q--) {
		char type;
		cin >> type;
		int units, pos;
		switch (type) {
		case 'a' : cin >> units;
			anticlockwiseRotate(net_rotaiton, units, n);
			printStringAfterRotation(str, n, net_rotaiton);
			break;
		case 'c' : cin >> units;
			clockwiseRotate(net_rotaiton, units, n);
			printStringAfterRotation(str, n, net_rotaiton);
			break;
		case 'p' : cin >> pos;
			cout << tellChar(str, n, net_rotaiton, pos) << endl;
			break;
		default : break;
		}
	}
	return 0;
}