// maxValueInArray.cpp
#include <iostream>
#include <algorithm>
#include <limits.h>
#define int long long
using namespace std;

int32_t main()
{
	int n, data;
	cin >> n;
	int ans = LLONG_MIN;
	for (int i = 0; i < n; ++i)
	{
		cin >> data;
		ans = max(ans, data);
	}
	cout << ans;
	return 0;
}