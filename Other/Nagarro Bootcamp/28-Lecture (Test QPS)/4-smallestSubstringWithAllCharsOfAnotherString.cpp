// smallestSubstringWithAllChars.cpp
#include<iostream>
#include<string>
#include<map>
#include<climits>
#define mci map<char,int>
using namespace std;

bool isUnwantedChar(char &ch, mci &mp1, mci &mp2) {
	if(mp2.count(ch) == 0) return true;
	if(mp1[ch]>mp2[ch]) return true;
	return false;
} 

string findMinLengthSubstring(string str,string pat) {

	int l1 = str.size();
	int l2 = pat.size();

	if(l2 > l1) return "-1";

	map<char,int> mp1,mp2;
	for(auto ch : pat) mp2[ch]++;
	int char_req = pat.size();
	int i = 0, j = 0;
	int mn = INT_MAX;

	int si=-1,ei=-1;

	for(; j < l1; j++) {
		//add calculation for the current window
		char ch = str[j];
		if(mp2.count(ch) != 0 and mp1[ch]<mp2[ch]) {
			char_req--;
		}
		mp1[ch]++;

		if(char_req == 0) {
			//contract - till we encounter unwanter chars
			while(isUnwantedChar(str[i],mp1,mp2)) {
				//remove calculations
				mp1[str[i]]--;
				i++;
			}
			//store the ans	- we have our required candidate
			int clen = j-i+1;
			if(clen < mn) {
				mn = clen;
				si = i;
				ei = j;
			}
		}
	}

	// while(j < str.size()) {	
	// 	//if we have window with all char 
	// 		//add calculations
	// 	char ch = str[j];
	// 	mp1[ch]++;
	// 	if(mp1[ch]<=mp2[ch]) {
	// 		char_req--;
	// 	}

	// 	if(char_req == 0) {
	// 		// cout<<"wf at "<<i<<" "<<j<<endl;
	// 		//reduce window
	// 		while(mp1[str[i]] > mp2[str[i]] or mp2.count(str[i]) == 0) {
	// 			char ch = str[i];
	// 			if(mp1[ch] > mp2[ch]) {
	// 				mp1[ch]--;
	// 			}
	// 			i++;
	// 		}
	// 		int clen = j-i+1;
	// 		if(clen<mn) {
	// 			si = i;
	// 			mn = clen;
	// 		}
	// 	}
	// 	j++;
	// }



	if(si!=-1) return str.substr(si,mn);
	return "-1";
}

int main() {
	string str = "this is a test string";
	string pat = "tist";

	cout<<findMinLengthSubstring(str,pat)<<endl;
	cout<<findMinLengthSubstring("geeksforgeeks", "ork")<<endl;

	return 0;
}


