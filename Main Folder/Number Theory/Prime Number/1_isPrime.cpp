// 1_isPrime.cpp
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
	if(num == 0 or num == 1) return false;
	if(num == 2) return true;

	for(int i=2; i<num; i++) {
		if(num%i == 0) return false;
	} 

	return true;
}

int main() {
	cout<<isPrime(4);
	return 0;
}