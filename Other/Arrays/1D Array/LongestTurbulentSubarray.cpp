// LongestTurbulentSubarray.cpp

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

// Order Of N3
class Solution {
public:
    int maxTurbulenceSize(vector<int> arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
        	for(int j=i; j<n; j++) {
        		bool isGreater;
        		int clen = 1;
        		if(i == j) ans = max(1,ans);
        		int k = i+1;
        		for(; k<=j;) {
        			if(k == i+1) {
        				if(arr[k] > arr[k-1]) isGreater = true;
        				else if(arr[k] < arr[k-1]) isGreater = false;
        				k++;
        			}
        			else {
                        if(arr[k] == arr[k-1])
                            break;
        				if((isGreater and arr[k] <= arr[k-1]))
        					break;
        				if(!isGreater and arr[k] >= arr[k-1])
        					break;
        				k++; 
        			}
        			isGreater = !isGreater;
        		}
        		if(k == j+1) ans = max(ans,j-i+1);
        	}
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxTurbulenceSize(vector<int> arr) {
        int s = 0;
        int e = 0;
        int n = arr.size();
        int ans = 0;
        vector<int> temp;
        for(int i=0; i<n-1; i++) {
            if(arr[i]<arr[i+1]) temp.pb(-1);
            else if(arr[i]>arr[i+1]) temp.pb(1);
            else temp.pb(0);
        }

        while(e < n) {
            // include the current el into calc
            bool cond = true;
            if(s != e) {
                if(temp[s] == -1 and temp[e] != 1) cond = false;
                if(temp[s] == 1 and temp[e] != -1) cond = false;
                if(temp[e] == 0) cond = false;
            }
            e++;
            // check if the condition is satisfied
            if(!cond) {
                s = e-1;
            }
            ans = max(e-s,ans);
        }
        return ans == 1 and arr.size() == 1 ?  1 : ans+1;
    }
};

int main() {
    Solution2 S;
    cout<<S.maxTurbulenceSize({9,4,2,10,7,8,8,1,9})<<endl;
    cout<<S.maxTurbulenceSize({4,8,12,16})<<endl;
    cout<<S.maxTurbulenceSize({16})<<endl;
	return 0;
}