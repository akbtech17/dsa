// maxAndMin.cpp
#include <iostream>
#include <algorithm>
#include <limits.h>
#define int long long
using namespace std;

int32_t main()
{
	int n, data;
	cin >> n;
	int max_ans = LLONG_MIN;
	int min_ans = LLONG_MAX;
	for (int i = 0; i < n; ++i)
	{
		cin >> data;
		max_ans = max(max_ans, data);
		min_ans = min(min_ans, data);
	}
	cout << max_ans << endl << min_ans;
	return 0;
}