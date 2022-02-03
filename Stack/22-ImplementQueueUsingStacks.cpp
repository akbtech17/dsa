// 22-ImplementQueueUsingStacks.cpp
// https://leetcode.com/problems/implement-queue-using-stacks/
// https://ide.codingblocks.com/s/635378

#include <bits/stdc++.h>
using namespace std;


// TC - 
// Push - O(1)
// Pop  - O(N)
// SC - O(N)
class MyQueue1 {
    stack<int> stk1, stk2;
public:
    void push(int x) {
        if(!stk1.empty()) stk1.push(x);
        else stk2.push(x);
    }
    
    int pop() {
        if(stk1.empty() and stk2.empty()) return -1;
        int ans;
        if(!stk1.empty()) {
            while(stk1.size()>1) {
                stk2.push(stk1.top());
                stk1.pop();
            }
            ans = stk1.top();
            stk1.pop();
            while(stk2.empty() == false) {
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
        else {
            while(stk2.size()>1) {
                stk1.push(stk2.top());
                stk2.pop();
            }
            ans = stk2.top();
            stk2.pop();
            while(stk1.empty() == false) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return ans;
    }
    
    int peek() {
        if(stk1.empty() and stk2.empty()) return -1;
        int ans;
        if(!stk1.empty()) {
            while(stk1.size()>1) {
                stk2.push(stk1.top());
                stk1.pop();
            }
            ans = stk1.top();
            stk2.push(ans);
            stk1.pop();
            while(stk2.empty() == false) {
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
        else {
            while(stk2.size()>1) {
                stk1.push(stk2.top());
                stk2.pop();
            }
            ans = stk2.top();
            stk1.push(ans);
            stk2.pop();
            while(stk1.empty() == false) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return ans;
    }
    
    bool empty() {
        return stk1.empty() and stk2.empty();
    }
};


// TC - 
// Push - O(N)
// Pop  - O(1)
// SC - O(N)
class MyQueue2 {
    stack<int> stk1, stk2;
public:
    void push(int x) {
        if(!stk1.empty()) {
        	while(!stk1.empty()) {
        		stk2.push(stk1.top());
        		stk1.pop();
        	}
        	stk2.push(x);
        	while(!stk2.empty()) {
        		stk1.push(stk2.top());
        		stk2.pop();
        	}
        }
        else {
        	while(!stk2.empty()) {
        		stk1.push(stk2.top());
        		stk2.pop();
        	}
        	stk1.push(x);
        	while(!stk1.empty()) {
        		stk2.push(stk1.top());
        		stk1.pop();
        	}
        }
    }
    
    int pop() {
        if(!stk1.empty()) {
        	int ans = stk1.top();
        	stk1.pop();
        	return ans;
        }
        else {
        	int ans = stk2.top();
        	stk2.pop();
        	return ans;
        }
        return -1;
    }
    
    int peek() {
        if(!stk1.empty()) return stk1.top();	
        else return stk2.top();
        return -1;
    }
    
    bool empty() {
        return stk1.empty() and stk2.empty();
    }
};
