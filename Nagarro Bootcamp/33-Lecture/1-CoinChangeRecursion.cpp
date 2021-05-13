#include<iostream>
#include<climits>
using namespace std;

int minCoins(int *coins, int n, int money) {
	//base case
	if(money == 0) return 0;

	//for money, we will check at this instance,
	//we might change it for which coins
	int minWays = INT_MAX;
	for(int i=0;i<n;i++) {
		int coin = coins[i];
		if(coin<=money) {
			//we can make change
			int ways = minCoins(coins,n,money-coin);
			if(ways != -1) minWays = min(minWays,1+ways); 
		}
	}
	return minWays == INT_MAX ? -1 : minWays;
}

int main() {
	//array of denomination
	int coins[] = {2,7,10};
	int n = 3;
	//find min no of denomination to make exchange
	cout<<minCoins(coins,n,15)<<endl;
	cout<<minCoins(coins,n,1)<<endl;
	return 0;
}