#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void c_p_c() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

bool mycompare(pair<int, int> act1, pair<int, int> act2) {
	return act1.second < act2.second;
}

int selectActivity(vector<pair<int, int>> activities) {
	if (activities.empty() == true) return 0;
	int ans = 1;
	sort(activities.begin(), activities.end(), mycompare);
	int prev_time = activities[0].second;

	for (int i = 1; i < activities.size(); i++) {
		if (prev_time <= activities[i].first) {
			ans++;
			prev_time = activities[i].second;
		}
	}
	return ans;
}

int main() {
	// c_p_c();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> activities;
		for (int i = 0; i < n; ++i) {
			int s, e;
			cin >> s >> e;
			activities.push_back(make_pair(s, e));
		}
		cout << selectActivity(activities) << endl;
	}
	return 0;
}