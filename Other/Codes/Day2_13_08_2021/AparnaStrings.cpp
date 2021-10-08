// AparnaStrings.cpp
#include<bits/stdc++.h>
using namespace std;

int totalTurns(char *input1, int input2, int input3){
    int n = input3;
    int m = input2;
    string s = "";
    for(int i=0;input1[i]!='\0';i++) s+=char(input1[i]);
    int len=s.length();
    int count=1;
    string q=s.substr(len-m,m)+s.substr(0,len-m);
    int cut=n;
    while(q!=s){
        q=q.substr(len-cut,cut)+q.substr(0,len-cut);
        if(cut==m){
            cut=n;
        }
        else{
            cut=m;
        }
        count++;
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int m,n;
        cin>>m>>n;
        cout<<totalTurns("abcd",m,n)<<"\n";
    }
}