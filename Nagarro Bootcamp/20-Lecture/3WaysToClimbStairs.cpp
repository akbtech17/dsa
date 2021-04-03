// 3WaysToClimbStairs.cpp
// https://www.geeksforgeeks.org/count-ways-reach-nth-stair/

#include <iostream>
using namespace std;

int countWays(int n, int k) {
	if (n == 0) return 1;
	int count = 0;
	for (int steps = 1; steps <= k; ++steps) {
		if (n - steps >= 0) count += countWays(n - steps, k);
	}
	return count;
}

int main() {
	int n = 4;
	int k = 2;
	cout << countWays(n, k);
	return 0;
}