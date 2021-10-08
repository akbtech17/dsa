// 1_LuckyFour.cpp
// https://www.codechef.com/problems/LUCKYFR

#include <bits/stdc++.h>
#define int long long
using namespace std;

int count4(int num) {
	int cnt =0 ;
	while(num) {
		if(num%10 == 4) cnt++;
		num /= 10;
	}
	return cnt;
}

int32_t main() {
	int t;
	cin>>t;
	while(t--) {
		int num;
		cin>>num;
		cout<<count4(num)<<endl;
	}
	return 0;
}