// 2uniquePermutations.cpp
//without using set or map
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void printPermutations(int *arr, int n , int i = 0) {
	if (i == n) {
		// print arr
		for (int j = 0; j < n; ++j)
			cout << arr[j] << " ";
		cout << endl;
		// cout << "perm found\n";
		return;
	}
	for (int j = i; j < n; ++j)
	{
		if (j != i and arr[j] == arr[i]) continue;
		swap(arr[i], arr[j]);
		printPermutations(arr, n, i + 1);
		//backtrack
		swap(arr[i], arr[j]);
	}
	return;
}

vector<string> ans;

void printPermutations2(string str, int n , int i = 0) {
	if (i == n) {
		// print str
		ans.push_back(str);
		// cout << "perm found\n";
		return;
	}
	for (int j = i; j < n; ++j)
	{
		if (j != i and str[j] == str[i]) continue;
		swap(str[i], str[j]);
		printPermutations2(str, n, i + 1);
		//backtrack
		swap(str[i], str[j]);
	}
	return;
}

int main() {
	// int n;
	// cin >> n;
	// int arr[100000] = {0};
	// for (int i = 0; i < n; i++) cin >> arr[i];

	int n;
	cin >> n;
	getchar();
	string str;
	for (int i = 0; i < n; ++i)
	{
		char ch;
		cin >> ch;
		str += ch;
		getchar();

	}
	printPermutations2(str, n);
	sort(ans.begin(), ans.end());
	for (auto el : ans)
	{
		for (auto ch : el) cout << ch << " ";
		cout << endl;
	}
	return 0;
}
