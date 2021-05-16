// 4-Structures.cpp
#include<bits/stdc++.h>
using namespace std;

struct Car {
	int arr[5];
	int val;
	string name;
};

int main() {
	Car c;
	c.arr[0] = 1;
	c.arr[1] = 2;
	c.arr[2] = 3;
	c.arr[3] = 4;
	c.arr[4] = 5;

	for(int i=0;i<5;i++) {
		cout<<c.arr[i]<<":";
	}

	return 0;
}