#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int t;
	cin >> t;
	while (t--) {
		int c1, c2, c3, c4;
		cin >> c1 >> c2 >> c3 >> c4;

		int nr, nc;
		cin >> nr >> nc;

		int rickshaw[1005], cabs[1005];

		for (int i = 0; i < nr; i++) cin >> rickshaw[i];
		for (int i = 0; i < nc; i++) cin >> cabs[i];

		// int ans = 0;

		int cost1 = 0;
		int cost2 = 0;

		for (int i = 0; i < nr; i++) {
			cost1 += min(c1 * rickshaw[i], c2);
		}
		cost1 = min(c3, cost1);

		for (int i = 0; i < nc; i++) {
			cost2 += min(c1 * cabs[i], c2);
		}
		cost2 = min(c3, cost2);

		int ans = min(cost1 + cost2, c4);
		cout << ans << endl;

	}
	return 0;
}