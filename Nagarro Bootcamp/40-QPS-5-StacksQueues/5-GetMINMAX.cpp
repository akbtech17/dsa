// 5-GetMINMAX.cpp
// https://leetcode.com/problems/min-stack/

#include<bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define vi vector<int>
using namespace std;

class MinMaxStack {
    vi stk;
    vi minStk;
    vi maxStk;
public:
    void push(int val) {
        int cmin = val;
        int cmax = val;

        if(!empty()) cmin = min(cmin,minStk[minStk.size()-1]);
        if(!empty()) cmax = max(cmax,maxStk[maxStk.size()-1]);

        stk.pb(val);
        minStk.pb(cmin);
        maxStk.pb(cmax);

        return;
    }
    
    void pop() {
        stk.ppb();
        minStk.ppb();
        maxStk.ppb();

        return;
    }
    
    int top() {
        return empty()? -1 : stk[stk.size()-1];
    }
    
    int getMin() {
        return empty()? -1 : minStk[minStk.size()-1];
    }

    int getMax() {
        return empty()? -1 : maxStk[maxStk.size()-1];
    }
    bool empty() {
        return stk.size() == 0;
    }
};

int main() {
	MinMaxStack stk;
    stk.push(-2);
    stk.push(0);
    stk.push(-3);
    cout<<stk.getMin()<<endl; // return -3
    stk.pop();
    cout<<stk.top()<<endl;    // return 0
    cout<<stk.getMin()<<endl; // return -2

    return 0;
}