#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define vi vector<int>
#define pi pair<int,int>
#define mi map<int,int>

using namespace std;

//there are n white n black dots, spaced in an array
//pos of black and white dots are given in two arrays
//we have to connect these black and white dots in such a way that
//total length is minimum

int connectWiresWithMinLength(vector<int> black, vector<int> white) {
	int ans = 0;
	//so greedily to minimize the length, we need to connect each black dot with the nearest white dot
	//lets sort the vect, and map each white and black dot
	sort(black.begin(), black.end());
	sort(white.begin(), white.end());
	for (int i = 0; i < black.size(); i++) {
		ans += abs(black[i] - white[i]);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> black, white;
	black.resize(n);
	white.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> black[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> white[i];
	}
	cout << connectWiresWithMinLength(black, white);
	return 0;
}