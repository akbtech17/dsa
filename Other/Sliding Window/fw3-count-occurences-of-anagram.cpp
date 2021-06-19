// fw3 - count - occurences - of - anagram.cpp
#include <bits/stdc++.h>
#include <string>
#include <map>
using namespace std;

void countAnagrams(string str, string t) {
	int k = t.size();
	int n = str.size();
	int s = 0;
	int e = 0;
	map<char, int> mp;
	for (auto ch : t) mp[ch]++;
	int req_chars = mp.size();
	int count = 0;

	while (e < n) {
		//add calculations
		if (mp.count(str[e]) != 0) {
			mp[str[e]]--;
			if (mp[str[e]] == 0) req_chars--;
		}
		//create window
		if (e - s + 1 < k) {
			e++;
		}
		//maintain window
		else if (e - s + 1 == k) {
			// cout << req_chars << endl;
			//find ans
			if (req_chars == 0) {
				count++;
			}
			//remove calculation for first index
			//slide
			if (mp.count(str[s]) != 0) {
				mp[str[s]]++;
				if (mp[str[s]]  == 1) req_chars++;
			}
			s++;
			e++;
		}
	}
	cout << count;
	return;
}

vector<int> findAnagrams(string str, string pat) {
   	vector<int> ans;	
	int s = 0;
	int e = 0 ;
	map<char,int> mp;

	for(auto el : pat) mp[el]++;
   	int req_char = mp.size();

   	while(e<str.length()) {
   		// firstly include the current 
   		// charater in calcualtion
   		if(mp.count(str[e])!=0) {
   			// if it is present in map
   			mp[str[e]]--;
   			if(mp[str[e]] == 0) req_char--;
   		}
   		int ws = e-s+1;
   		// if we didnt reach ws 
   		if(ws < pat.size()) e++;
   		else {
   			if(req_char == 0) ans.push_back(s);
   			if(mp.count(str[s])!=0) {
	   			// if it is present in map
	   			mp[str[s]]++;
	   			if(mp[str[s]] == 1) req_char++;
   			}
   			s++;
   			e++;
   		}
   	}

   	return ans;
}

int main() {
	string s = "aabaabaa", t = "aaba";
	cin >> s >> t;

	countAnagrams(s, t);

	return 0;
}