// MaximumLengthOfAConcatenatedStringWithUniqueChar.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
	int mxLen;
public:
	bool isUnique(string s) {
		if(s.size() == 0) return true;
		map<char,int> mp;
		for(auto ch : s) {
			if(mp.count(ch) > 0) return false;
			mp[ch] = 1;
		}
		return true;
	}
	void recurse(vector<string>& arr, int i=0 , string temp ="") {
		if(i == arr.size()) {
			if(isUnique(temp)) mxLen = max(mxLen,int(temp.size()));
			return;
		}
		recurse(arr,i+1, temp + arr[i]);
		recurse(arr,i+1, temp);
		return;
	}
    int maxLength(vector<string> arr) {
        mxLen = 0;
        recurse(arr);
        return mxLen;
    }
};

int main() {
	Solution S;
	cout<<S.maxLength({"un","iq","ue"})<<endl;
	cout<<S.maxLength({"hzmvgsjlwu","lzwvirej","euajvm","dnucibjesamyzwqxpr","zpbkgwefiths","ezplg","sbqjflvnmweocuaxrt","wcnied","oxprjyiz","wvenqbutfzmjkslcg","knu","ulcdxsjqinvopwezya","hxbgv","pwotlagycjdnfkuzv","ldhkgbicapfzvqjremxy"})<<endl;

	return 0;
}