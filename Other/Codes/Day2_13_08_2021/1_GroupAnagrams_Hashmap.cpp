// 1_GroupAnagrams_Hashmap.cpp
// https://practice.geeksforgeeks.org/problems/k-anagrams-1/0


#include<bits/stdc++.h>
// using std::cout;
// using std::endl;
// using std::vector;
using namespace std;

// Expected Time Complexity: O(N*|S|*log|S|), 
// where |S| is the length of the strings.

// Expected Auxiliary Space: O(N*|S|), 
// where |S| is the length of the strings.

class Solution {
public:
	void printAns(vector<vector<string>> ans) {
		for(auto v : ans) {
			for(auto s : v) cout<<s<<" ";
			cout<<endl;
		}
		return;
	}
    vector<vector<string>> groupAnagrams(vector<string> strs) {
        vector<vector<string>> ans;
        map<map<char,int>,vector<string>> mp_fre;

        for(auto str : strs) {
        	map<char,int> fre_temp;
        	for(auto ch : str) {
        		fre_temp[ch]++;
        	}
        	// if(mp_fre.count())
        	mp_fre[fre_temp].push_back(str);
        }

        for(auto p : mp_fre) {
        	ans.push_back(p.second);
        }

        printAns(ans);
        return ans;
    }
};

int main() {
	Solution S;
	S.groupAnagrams({"eat","tea","tan","ate","nat","bat"});
	S.groupAnagrams({""});
	S.groupAnagrams({"a"});
	S.groupAnagrams({"act","god","cat","dog","tac"});
	S.groupAnagrams({"no","on","is"});
	S.groupAnagrams({"act","god","cat","dog","tac"});

	return 0;
}