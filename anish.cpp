// anish.cpp
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int person;
    cin>>person;
    int k;
    cin>>k;
 
    // Placeholder array for person
    vector<int> a(person);
 
    // Assign placeholders from 1 to N (total person)
    for (int i = 0; i < person; i++) {
        a[i] = i + 1;
    }
 
    // Will start the game from 1st person (Which is at
    // placeholder 0)
    int pos = 0;
 
    // Game will be continued till we end up with only one
    // person left
    while (a.size() > 1) {
        
        pos+=(k+1);
      
        pos %= a.size();
    
        a.erase(a.begin() + pos);
    }
    cout << a[0];
 
    return 0;
}