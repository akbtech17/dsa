// 12-MinMaxStack-ConstSpace.cpp

#include <iostream>
#include <stack>
using std::cout;
using std::stack;
using std::min;
using std::max;
using std::endl;


// time complexcity  -> O(1)
// space complexcity -> O(1) - No Extra Stacks are used!

class MinStack {
public:
    stack<int> stk;
    stack<int> mn;
    stack<int> mx;

    MinStack() {
        // ...nothing here
    }
    
    void push(int val) {
        if(stk.empty()) {
        	stk.push(val);
        	mn.push(val);
        	mx.push(val);
    	}
    	else {
    		stk.push(val);
    		mn.push(min(mn.top(),val));
    		mx.push(max(mx.top(),val));
    	}
    	return;
    }
    
    void pop() {
        if(!stk.empty()) {
        	stk.pop();
        	mn.pop();
        	mx.pop();
        }
        return;
    }
    
    int top() {	
        return stk.empty() ? -1 : stk.top();
    }
    
    int getMin() {
        return stk.empty() ? -1 : mn.top();
    }

    int getMax() {
        return stk.empty() ? -1 : mx.top();
    }
};

int main() {
	MinStack mnstk;
	mnstk.push(-2);
	mnstk.push(0);
	mnstk.push(-3);

	cout<<mnstk.getMin()<<" "<<mnstk.getMax()<<endl;
	mnstk.pop();
	cout<<mnstk.top()<<endl;
	cout<<mnstk.getMin()<<" "<<mnstk.getMax()<<endl;

	return 0;
}