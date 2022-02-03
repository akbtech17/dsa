// tr3.cpp
#include<bits/stdc++.h>
using namespace std;

bool isUnwanted(char ch, int* mp1, int* mp2) {
	if(mp2[ch-'a'] == 0) return true;
	if(mp1[ch-'a']>mp2[ch]) return true;
	return false;
}

int recurse(string str, int *mp1, int*mp2, int cnt,int s, int e) {
	if(cnt == 0) return 0;
	if(s>e) return 0;
	int w1 = 0;
	int w2 = 0;

	// if(isUnwanted(str[s],mp1,mp2) and isUnwanted(str[e],mp1,mp2)) {
	// 	mp1[str[s]-'a']--;
	// 	cnt--;
	// 	mp1[str[e]-'a']--;
	// 	cnt--;

	// 	return 2+recurse(str,mp1,mp2,cnt,s+1,e-1);
	// }
	// else if(isUnwanted(str[s],mp1,mp2) and !isUnwanted(str[e],mp1,mp2)){
	// 	mp1[str[s]-'a']--;
	// 	cnt--;
	// 	return 1+recurse(str,mp1,mp2,cnt,s+1,e);
	// }

	// else if(isUnwanted(str[s],mp1,mp2) and !isUnwanted(str[e],mp1,mp2)){
	// 	mp1[str[e]-'a']--;
	// 	cnt--;
	// 	return 1+recurse(str,mp1,mp2,cnt,s,e-1);
	// }

	// w1 = recurse(str,mp1,mp2,cnt,s+1,e);
	// w2 = recurse(str,mp1,mp2,cnt,s,e-1);

	if(isUnwanted(str[s],mp1,mp2)) {
		cout<<str[s]<<" is removed\n";
		mp1[str[s]-'a']--;
		return 1+recurse(str,mp1,mp2,cnt-1,s+1,e);
	}

	if(isUnwanted(str[e],mp1,mp2)) {
		cout<<str[e]<<" is removed\n";

		mp1[str[e]-'a']--;
		return 1+recurse(str,mp1,mp2,cnt-1,s,e-1);
	}

	if(cnt>0) {
		mp1[str[s]-'a']--;
		int w1 = 1+recurse(str,mp1,mp2,cnt,s+1,e);
		mp1[str[s]-'a']++;
		mp1[str[e]-'a']--;
		int w2 = 1+recurse(str,mp1,mp2,cnt,s,e-1);
		mp1[str[e]-'a']++;
		
		if(w1<w2) {
			cout<<str[s]<<" is removed\n";

			mp1[str[s]-'a']--;
			return w1;
		}
		cout<<str[e]<<" is removed\n";
		
		mp1[str[e]-'a']--;
		return w2;
	} 
	return 0;
}

int solve(string s1, string s2) {
	int mp1[26] = {0};
	int mp2[26] = {0};

	memset(mp1,0,sizeof(mp1));
	memset(mp2,0,sizeof(mp2));

	for(int i=0;i<s1.size();i++) mp1[s1[i]-'a']++;
	for(int i=0;i<s2.size();i++) mp2[s2[i]-'a']++;

		for(int i=0;i<26;i++) cout<<mp1[i]<<" ";
		cout<<endl;
	for(int i=0;i<26;i++) cout<<mp2[i]<<" ";

	int ui = -1;
	int uj = -1;
	int i = 0;
	int j = s1.size()-1;

	int nuc = 0;

	for(int i=0;i<s1.size();i++) {
		char ch = s1[i];
		if(isUnwanted(ch,mp1,mp2)) {
			nuc++;
		}
	}
	cout<<"\nno of unwanted char"<<nuc<<endl;
	for(int i=0;i<26;i++) cout<<mp1[i]<<" ";
		cout<<endl;
	for(int i=0;i<26;i++) cout<<mp2[i]<<" ";
			cout<<endl;
	int noO = recurse(s1,mp1,mp2,nuc,0,s1.size()-1);

	// for(int i=0;i<26;i++) {
	// 	noO+=mp2[i]-mp1[i];
	// }

	return noO;

}

int main() {
	cout<<endl<<solve("difficult","luafftlcb");

	return 0;
}