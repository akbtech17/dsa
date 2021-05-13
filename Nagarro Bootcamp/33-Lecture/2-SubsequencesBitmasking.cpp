// 2-SubsequencesBitmasking.cpp
#include<bits/stdc++.h>
using namespace std;

string findSubs(int num, string s) {
	int itr = 0;
	string sub = "";
	while(num>0) {
		//extract last bit
		if(num&1 != 0) sub += s[itr];
		itr++;
		num = num>>1;  
	}
	return sub;
}

void printSubs(string s) {
	int ns = pow(2,s.size());
	cout<<ns;
	for(int i=0;i<ns;i++) {
		//find the substring
		cout<<findSubs(i,s)<<endl;
	}
	return;
}

int main() {
	printSubs("abc");
	return 0;
}