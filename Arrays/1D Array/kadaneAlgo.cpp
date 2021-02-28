#include <iostream>
using namespace std;

int kadanesSum(int *arr, int n) {
	int curr_sum;
	int overall_sum;

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			curr_sum = overall_sum = arr[i];
			continue;
		}
		/*agar peeche se sum pos
		ara hai toh max contribute krne ke liye
		element usi me add hojayga*/
		if (curr_sum >= 0) curr_sum += arr[i];
		/*nhi toh apni nyi train bna lega, kahega maa chuday sab
		mai nayi train bna rha*/
		else curr_sum = arr[i];
		overall_sum = max(overall_sum, curr_sum);
	}
	return overall_sum;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, arr[100000];
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> arr[i];
		cout << kadanesSum(arr, n) << endl;
	}
	return 0;
}