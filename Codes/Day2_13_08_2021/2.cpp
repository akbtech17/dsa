// 2.cpp
#include<bits/stdc++.h>
// #define vi vector<int>
// #define mp make_pair
// #define int long long
using namespace std;


int solve(int arr[], int m, int n ) {
	int i, j, x, y;
    int dp[n + 1][m];
    for (i = 0; i < m; i++)
        dp[0][i] = 1;
    for (i = 1; i < n + 1; i++) {
        for (j = 0; j < m; j++) {
            x = (i-arr[j] >= 0) ? dp[i - arr[j]][j] : 0;
            y = (j >= 1) ? dp[i][j - 1] : 0;
            dp[i][j] = x + y;
        }
    }
    return dp[n][m - 1];
}

int32_t main() {
	int arr[] = {1, 2, 5, 10};
    int m = sizeof(arr)/sizeof(arr[0]);
    
    int n;
    cin>>n;

    cout << solve(arr, m, n);
    return 0;
	
}