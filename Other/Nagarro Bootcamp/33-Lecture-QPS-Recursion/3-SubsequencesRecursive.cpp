// 3-SubsequencesRecursive.cpp
#include<bits/stdc++.h>
using namespace std;

void Subsequences(string s, int i, int mv) {
	//base case
	if(i == mv) return;
	//do work for 1
	int num = i;
	int idx = 0;

	while(num) {
		if(num&1 == 1) {
			cout<<s[idx];
		}
		idx++;
		num=num>>1;
	}
	cout<<endl;

	//recurse on other
	Subsequences(s,i+1,mv);
}

int main() {
	string s = "abc";
	int mv = pow(2,s.size());
	Subsequences(s, 0, mv);
	return 0;
}