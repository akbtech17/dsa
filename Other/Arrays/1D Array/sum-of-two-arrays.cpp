// sum - of - two - arrays.cpp
#include <iostream>
#define MX 1005
using namespace std;

int main() {
	int arr1[MX] = {0}, arr2[MX] = {0};
	int n1, n2;
	cin >> n1;
	for (int i = 0; i < n1; ++i) cin >> arr1[i];
	cin >> n2;
	for (int i = 0; i < n2; ++i) cin >> arr2[i];

	int carry = 0;
	int ans[MX] = {0};
	int k = 0;

	for (; n1 > 0 and n2 > 0; n1--, n2--) {
		int sum = arr1[n1 - 1] + arr2[n2 - 1] + carry;
		carry = sum / 10;
		ans[k++] = sum % 10;
	}


	for (; n1 > 0 ; n1--) {
		int sum = arr1[n1 - 1] + carry;
		carry = sum / 10;
		ans[k++] = sum % 10;
	}

	for (; n2 > 0; n2--) {
		int sum = arr2[n2 - 1] + carry;
		carry = sum / 10;
		ans[k++] = sum % 10;
	}

	for (; carry > 0;) {
		int sum = carry;
		carry = sum / 10;
		ans[k++] = sum % 10;
	}

	for (int i = k - 1; i >= 0; --i) cout << ans[i] << ", ";

	cout << "END";

	return 0;
}
