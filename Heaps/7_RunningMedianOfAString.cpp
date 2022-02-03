// 7_RunningMedianOfAString.cpp
// https://leetcode.com/problems/find-median-from-data-stream/
// https://ide.codingblocks.com/s/639228

// TC - O(NLogN)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    double median;
public:
    void addNum(int num) {
        int n1 = pq1.size();
        int n2 = pq2.size();

        if(n1 == 0 and n2 == 0) {
            pq1.push(num);
            median = num;
        }

        else if(n1 == n2) {
            if(num < median) {
                pq1.push(num);
                median = pq1.top();
            }
            else {
                pq2.push(num);
                median = pq2.top();
            }
        }

        else if (n1 > n2) {
            if(num < median) {
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
            else pq2.push(num);
            median = (pq1.top()+pq2.top()) /2.00;
        }
        else if(n1 < n2) {
            if(num > median) {
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }
            else pq1.push(num);
            median = (pq1.top()+pq2.top()) /2.00;
        }
    }
    
    double findMedian() {
       return median;
    }
};

