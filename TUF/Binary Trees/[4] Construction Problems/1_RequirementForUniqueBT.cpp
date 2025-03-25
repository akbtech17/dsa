#include <iostream>
using namespace std;

// TC: O(1)
// Sc: (1)
class Solution {
public:
	bool uniqueBinaryTree(int a, int b) {
		if (a == b)
			return false;
		else if ((a == 1 && b == 3) || (a == 3 && b == 1))
			return false;
		return true;
	}
};