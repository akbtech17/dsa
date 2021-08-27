// 2_RowWithMax1_2dArray.cpp
// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution{
public:
	int rowWithMax1s(vector<vector<int>>& arr, int n, int m) {
	    int ptr = m-1;
	    int i = 0;
	    int ans = -1;
	    while(i < n) {
	    	while(arr[i][ptr] == 1) {
	    		ptr--;
	    		ans = i;
	    	}	    	
	    	i++;
	    }
	    return ans;
	}
};

int main() {
	Solution sol;
	//    
	vector<vector<int>> v1({
		   {0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}
    });

    vector<vector<int>> v2({{0, 0}, {1, 1}});

	cout<<sol.rowWithMax1s(v1,v1.size(),v1[0].size())<<endl;
	cout<<sol.rowWithMax1s(v2,v2.size(),v2[0].size())<<endl;

	return 0;
}