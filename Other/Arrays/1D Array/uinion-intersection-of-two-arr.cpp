// uinion - intersection - of - two - arr.cpp
// playing - with - good - str.cpp
#include <iostream>
#include <algorithm>
#include <set>
#define MX 1005
using namespace std;

void printUnion(int* arr1, int n1, int* arr2, int n2) {
	int i = 0;
	int j = 0;
	set<int> s;
	while (i < n1 and j < n2) {
		if (arr1[i] < arr2[j]) {
			s.insert(arr1[i]);
			i++;
		}
		else if (arr1[i] > arr2[j]) {
			s.insert(arr2[j]);
			j++;
		}
		else {
			s.insert(arr1[i]);
			i++;
			j++;
		}
	}

	while (i < n1)
	{	s.insert(arr1[i]);
		i++;
	}

	while (j < n2)
	{
		s.insert(arr2[j]);
		j++;
	}

	for (auto el : s)
	{
		cout << el << " ";
	}
	return;

}

void printIntersection(int* arr1, int n1, int* arr2, int n2) {


	int i = 0;
	int j = 0;
	set<int> s;
	while (i < n1 and j < n2) {
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else {
			s.insert(arr2[j]);
			i++;
			j++;
		}
	}

	for (auto el : s)
	{
		cout << el << " ";
	}
	return;
}

int main() {
	int arr1[MX] = {0}, arr2[MX] = {0};
	int n1 = 0, n2 = 0;
	cin >> n1;
	for (int i = 0; i < n1; ++i) cin >> arr1[i];
	cin >> n2;
	for (int i = 0; i < n2; ++i) cin >> arr2[i];

	sort(arr1, arr1 + n1);
	sort(arr2, arr2 + n2);

	printUnion(arr1, n1, arr2, n2);
	cout << endl;
	printIntersection(arr1, n1, arr2, n2);
	return 0;
}