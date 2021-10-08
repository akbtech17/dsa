// aatmic.cpp

#include<iostream>
#include<climits>
using namespace std;
 
int maxSubArraySum(int a[], int size)
{
	int max = INT_MIN;
	int st = -1;
	int en = -1;
	int csum = 0;
	for(int i=0; i<size; i++) {
		if(a[i]>0) {
			if(st!=-1) {}
		}
		else {

		}
	}
    
    return max_so_far;
}
 
/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}