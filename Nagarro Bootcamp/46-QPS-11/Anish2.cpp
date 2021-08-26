// Anish.cpp
#include<bits/stdc++.h>
using namespace std;

vector<string> extractWords(string str)
{
	vector<string> v;
    string word;
    stringstream iss(str);
    while (iss >> word)
        v.push_back(word);
    return v;
}

string leftrotate(string s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
    return s;
}

string rightrotate(string s, int d) {
   s = leftrotate(s, s.length()-d);
   return s;
}

void rotate(vector<string> &v, int k) {
	for(int i=0; i<v.size(); i++) v[i] = rightrotate(v[i],k);
	return; 
}

int rotateWords(string input1, int input2)
{
	string str = input1;
	int k = input2;
	vector<string> v1 = extractWords(str);
	vector<string> v2(v1);
	rotate(v2,k);
	// for(auto el : v2) cout<<el<<" ";
	// cout<<endl;
	int ans = 0;
	for(int i=0 ;i<v1.size(); i++) {
		if(v1[i] == v2[i]) ans++;
	}
    return ans;
}

int main()
{
    cout<<rotateWords("llohe ereth",2)<<endl;
    cout<<rotateWords("adaada",3)<<endl;
    return 0;
}