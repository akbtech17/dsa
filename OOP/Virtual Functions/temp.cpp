// temp.cpp

#include<bits/stdc++.h>
#define ll long long
using namespace std;

char kThCharaterOfDecryptedString(string s, ll k) {
	string ans = "";
	ll n = s.size();

	for(ll i=0;i<n;i++) {
		string t = "";
		string f = "";

		while(i<n and isalpha(s[i])) {
			t+=s[i];
			i++;
		}

		while(i<n and isdigit(s[i])) {
			f += s[i];
			i++;
		}

		ll num = stoi(f);
		while(num--) {
			ans.append(t);
		}

		i--;
	}

	return ans[k-1];
}

int main() {
	string s;
	long long int k;
	cin>>s>>k;
	// cout<<kThCharaterOfDecryptedString(s,k)<<endl;
	kThCharaterOfDecryptedString(s,k);

	return 0;
}