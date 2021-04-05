#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 6
// -1 0 1 2 -1 -4
// 0


//approach 1 - using 3 nested loops
//with duplicates
//tc n cube
//sc const
void sum3WithDuplicates(int arr[], int n, int sum) {
	if (n < 3) return;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				if (arr[i] + arr[j] + arr[k] == sum) {
					cout << arr[i] << "," << arr[j] << "," << arr[k] << endl;
				}
			}
		}
	}
	return;
}

//now we can modify code to remove duplicates
//first sort arr
//for i idx check if there is no i-1 same element, if so skip that ele

void sum3WithoutDuplicates(int arr[], int n, int sum) {
	if (n < 3) return;
	//sort the arr
	sort(arr, arr + n);

	for (int i = 0; i < n; ++i)
	{
		//check for dup
		if (i > 0 and arr[i - 1] == arr[i]) continue; //skip for dup i
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				if (arr[i] + arr[j] + arr[k] == sum) {
					cout << arr[i] << "," << arr[j] << "," << arr[k] << endl;
				}
			}
		}
	}
	return;
}


//approach - 2
//using hashmap
//lets first do for 2Sum

void Sum2HM(int arr[], int n, int sum) {
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i)
	{
		unordered_set<int> s;
		int value = sum - arr[i];

		if (s.find(value) != s.end()) {
			cout << arr[i] << "," << value << endl;
		}

		s.insert(arr[i]);
	}
	return;
}

int main() {
	int arr[100000] = {0};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int sum;
	cin >> sum;
	// sum3WithDuplicates(arr, n, sum);
	// sum3WithoutDuplicates(arr, n, sum);
	Sum2HM(arr, n, sum);
	return 0;
}