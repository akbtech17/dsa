#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#define vi vector<int>
#define pi pair<int,int>
#define mi map<int,int>
#define mp make_pair
#define pb push_back
#define int long long

using namespace std;


int32_t main() {
	int t;
	cin >> t;
	int csort[100000] = {0};
	while (t--) {
		int n;
		cin >> n;
		int rank;
		string name;
		memset(csort, 0, sizeof(csort));
		for (int i = 0; i < n; ++i)
		{
			cin >> name >> rank;
			csort[rank]++;
		}
		//greedy approach = actual-prefered
		int actual_rank = 1;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			while (csort[i]) {
				ans += abs(actual_rank - i);
				actual_rank++;
				csort[i]--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}