// PrintCodes.cpp
#include<iostream>
#include<string>
using namespace std;

void recurse(string str, int i = 0, string ans="") {
	if(i == str.size()) {
		cout<<ans<<endl;
		return;
	}
	int n1 = stoi(str.substr(i,1));
	if(n1!=0) {
		char ch = 'A'+n1-1;
		// ans+=ch;
		recurse(str,i+1,ans+ch);
	}
	int n2 = stoi(str.substr(i,2));
	if(str[i]!='0' and i+1<str.size() and n2<=26) {
		char ch = 'A'+n2-1;
		recurse(str,i+2,ans+ch);
	}
	return;
}

int main() {
	string str = "123";
	recurse(str);
	return 0;
}