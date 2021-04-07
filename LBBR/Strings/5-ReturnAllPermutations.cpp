// 5 - PrintAllPermutations.cpp
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define vs vector<string>
using namespace std;

void permute(string str, vs &permutations, int i = 0) {
	if (i == str.size()) {
		//print ans
		// cout << str << endl
		permutations.push_back(str);
		return;
	}

	for (int itr = i; itr < str.size(); ++itr) {
		swap(str[i], str[itr]);
		permute(str, permutations, i + 1);
		//backtrack
		swap(str[i], str[itr]);
	}

	return;
}

vs findAllPermutations(string str) {
	vs permutations;
	permute(str, permutations);
	sort(permutations.begin(), permutations.end());
	return permutations;
}

int main() {
	vs ans = findAllPermutations("abc");
	for (auto el : ans) cout << el << endl;
	return 0;
}