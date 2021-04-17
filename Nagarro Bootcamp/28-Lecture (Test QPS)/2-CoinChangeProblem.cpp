// CoinChangeProblem.cpp
#include<iostream>
#include<set>
#define ms multiset<int> 
using namespace std;

int waysToMakeChange(int money, int coins[], int n, int coin,ms s) {
	if(money<0) return 0;
	if(money == 0) {
		//print set
		cout<<"{";
		for(auto el : s) cout<<el<<", ";
		cout<<"}\n";
		return 1;
	}
	if(money>0 and coin == n) {
		return 0;
	}
	int ans = 0;
	s.insert(coins[coin]);
	int inc = waysToMakeChange(money-coins[coin],coins, n, coin,s);
	s.erase(s.lower_bound(coins[coin]));
	int dinc = waysToMakeChange(money,coins,n,coin+1,s);
	return inc+dinc;
}

int main() {
	int money = 4;
	int coins[] = {1,2,3};
	int n = sizeof(coins)/sizeof(int);
	ms s;
	cout<<waysToMakeChange(money,coins,n,0,s);

	return 0;
} 