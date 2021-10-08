// 5-HammingDistance.cpp

// number of different bits among two given integers

#include<bits/stdc++.h>
using namespace std;

// tc = 32bit
int hammingDistance(int x, int y) {
	int cnt = 0;

	for(int i=0;i<32;i++) {
		int mask = 1<<i;
		int x_bit = x&mask?1:0;
		int y_bit = y&mask?1:0;

		if(x_bit!=y_bit) cnt++;
	}

	return cnt;	
}

// tc
int hammingDistance2(int x, int y) {
	int cnt = 0;
	int xr = x^y;
	//now count the set bits
	return  __builtin_popcount(xr);
	while(xr>0) {
		cnt++;
		xr = xr&(xr-1);
	}
	return cnt;	
}

int main() {
	cout<<hammingDistance(10,5)<<endl;
	cout<<hammingDistance(20,25)<<endl;

	cout<<hammingDistance2(10,5)<<endl;
	cout<<hammingDistance2(20,25)<<endl;

	return 0;
}