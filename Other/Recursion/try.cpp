// try.cpp
#include<bits/stdc++.h>
using namespace std;



int main() {
	string s = "my name is anshul bansal";
	char *arr = new char[s.size()+1];

	strcpy(arr,s.c_str());

	for(int i=0;i<s.size();i++) {
		cout<<arr[i];
	}

	char*  temp = strtok(arr," ");
	// cout<<temp<<endl;
	while(temp!=NULL) {
		cout<<temp<<endl;
		temp = strtok(NULL," ");
	}


	string f = "name";
	int  pos = s.find(f);
	cout<<pos;

	return 0;
}