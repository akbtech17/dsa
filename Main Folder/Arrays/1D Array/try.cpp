#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
#define inv(v,n) for(int i=0;i<n;i++) cin>>v[i];
#define prv(v,n) for(int i=0;i<n;i++) cout<<v[i]<<" ";
using namespace std;

bool compare(int n1, int n2) {
	return n1 < n2;
}

void smallestDiffTriplet(vi v1, vi v2, vi v3, int n) {
	int mn_diff = INT_MAX;
	int sum = INT_MAX;
	vi ans;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				int mx = max(v1[i], max(v2[j], v3[k]));
				int mn = min(v1[i], min(v2[j], v3[k]));
				int curr_diff = mx - mn;
				int csum = v1[i] + v2[j] + v3[k];
				if (curr_diff < mn_diff ) {
					ans.clear();
					ans.pb(v1[i]);
					ans.pb(v2[j]);
					ans.pb(v3[k]);
					mn_diff = curr_diff;
					sum = csum;
				}
				else if (curr_diff == mn_diff and csum < sum) {
					ans.clear();
					ans.pb(v1[i]);
					ans.pb(v2[j]);
					ans.pb(v3[k]);
					mn_diff = curr_diff;
					sum = csum;
				}
			}
		}
	}
	sort(ans.begin(), ans.end(), compare);
	prv(ans, 3);
	return;
}

int main() {
	int n;
	cin >> n;
	vi v1(n), v2(n), v3(n);
	inv(v1, n);
	inv(v2, n);
	inv(v3, n);

	smallestDiffTriplet(v1, v2, v3, n);
	return 0;
}