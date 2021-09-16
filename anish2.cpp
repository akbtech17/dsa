// anish2.cpp
// #include <bits/stdc++.h>
// using namespace std;

// int solve(int P, int E, int p, int e) {

// }

// int main() {
// 	int P,E,p,e;
// 	cin>>P>>E>>p>>e;
// 	solve(P,E,p,e);
// 	return 0;
// }

#include <iostream>
using namespace std;
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int main() {
    int n,m,p,e;
    cin>>n>>m>>p>>e;
    int ans1 = fact(n) / (fact(p) * fact(n - p));
    int ans2= fact(m) / (fact(e) * fact(m - e));
    cout<<ans1*ans2<<endl;
}