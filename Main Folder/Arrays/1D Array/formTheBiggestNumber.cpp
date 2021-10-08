#include <iostream>
#include <algorithm>
#define ll long long
#include<math.h>
using namespace std;

// 1
// 4
// 54 546 548 60

bool mycomp(string s1, string s2) {
	string s12 = s1.append(s2);
	string s21 = s2.append(s1);
	return s12 > s21;
}

void formTheBiggestNumber1() {
	int n;
	cin >> n;
	string arr[105];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, mycomp);
	for (auto el : arr) cout << el;
	cout << endl;
}


int digitOfNum(ll num) {
	int ans = 0;
	while (num > 0) {
		ans++;
		num /= 10;
	}
	return ans;
}

void formTheBiggestNumber2() {
	int n;
	cin >> n;
	ll arr[105];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	//bubble sort
	for (int i = 0; i < n - 1; ++i)
	{
		bool isSwapped = false;
		for (int j = 0; j < n - i; ++j)
		{
			ll ab, ba;
			ll a = arr[j];
			ll b = arr[j + 1];
			ab = (a * pow(10, digitOfNum(b)) + b);
			ba = (b * pow(10, digitOfNum(a)) + a);
			if (ba > ab) {
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped) break;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
	}
	cout << endl;

	return;

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		formTheBiggestNumber2();
	}
	return 0;
}