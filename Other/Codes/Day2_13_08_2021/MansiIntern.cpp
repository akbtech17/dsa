// MansiIntern.cpp
#include <bits/stdc++.h>
using namespace std;


int internNumber(int input1, int input2) {
	int n = input1;   // number of interns
	int k = input2;   // password used
    

    int **pass = new int*[n+1];
    for(int i=0;i<n;i++) {
    	pass[i] = new int[52];
    }
    // int prev = 0;
	for(int day=0; day<50; day++) {
		// memset(pass,0,sizeof(pass));
		for(int intern=0; intern<n; intern++) {
			if(day == 0)pass[intern][day] = (5000*(intern));
			if(day != 0) pass[intern][day] = pass[intern][day-1] + 5000 + (day);
			// cout<<pass[intern][day]<<endl;
			// prev = pass[intern][day];
			if(pass[intern][day] == k) return intern;
		}
	}
    return -1;
}
 
int main()
{
    // cout<<internNumber(10,25003)<<endl;
    cout<<internNumber(2,5000)<<endl;
    return 0;
}