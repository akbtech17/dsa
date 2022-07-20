#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(int h1, int h2) {
    int ans = 0;
    int h11 = h1, h22 = h2;
    while(h11 != h22) {
        cout<<h11<<" "<<h22<<endl;
        if(h11 < h22) {
            int diff = h22-h11;
            if(diff < h1) {
                h11+=h1;
                h22+=h2;
            }
            else {
                h11+=h1;
            }
        }
        else {
            int diff = h11-h22;
            if(diff < h2) {
                h11+=h1;
                h22+=h2;
            }
            else {
                h22+=h2;
            }
        }
        ans++;
    }
    return ans;
}

int32_t main() {
    int h1, h2;
    cin>>h1>>h2;
    cout<<solve(h1,h2);
    return 0;
}
