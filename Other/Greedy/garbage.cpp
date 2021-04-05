#include <iostream>
#include <ctype.h>
#include <vector>
#define ll long long
using namespace std;

void storeInFeqMap(ll *map, int num) {
	ll mask = 1;
	mask = (mask << num);
	*map = (*map | mask);
	// cout<<mask<<endl;
	return;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
	ll map = 0;
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++) {
		storeInFeqMap(&map, nums[i]);
	}

	for (int i = 1; i <= nums.size(); ++i)
	{
		ll mask = 1;
		mask = (mask << i);
		if ((map & mask) == 0) {
			ans.push_back(i);
		}
	}
	return ans;
}

int main () {
	vector<int> v = {4, 3, 2, 7, 8, 2, 3, 1};
	vector<int> ans = findDisappearedNumbers(v);
	for (auto el : ans) cout << el << " " ;
	return 0;
}


