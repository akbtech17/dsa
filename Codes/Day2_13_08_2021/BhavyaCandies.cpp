// BhavyaCandies.cpp
#include <bits/stdc++.h>
using namespace std;

struct Result {
	Result() : output1(){};
	int output1[100];
};
 
Result toffees(int input1, int input2) {
	int n = input1;
	int k = input2;
    // Count number of complete turns
    int count = 0;
 
    // Get the last term
    int ind = 1;
 
    // Stores the number of candies
    int arr[k];
 
    memset(arr, 0, sizeof(arr));
 
    while (n) {
 
        // Last term of last and
        // current series
        int f1 = (ind - 1) * k;
        int f2 = ind * k;
 
        // Sum of current and last  series
        int sum1 = (f1 * (f1 + 1)) / 2;
        int sum2 = (f2 * (f2 + 1)) / 2;
 
        // Sum of current series only
        int res = sum2 - sum1;
 
        // If sum of current is less than N
        if (res <= n) {
            count++;
            n -= res;
            ind++;
        }
        else // Individually distribute
        {
            int i = 0;
 
            // First term
            int term = ((ind - 1) * k) + 1;
 
            // Distribute candies till there
            while (n > 0) {
 
                // Candies available
                if (term <= n) {
                    arr[i++] = term;
                    n -= term;
                    term++;
                }
                else 
                {
                    arr[i++] = n;
                    n = 0;
                }
            }
        }
    }
 
    for (int i = 0; i < k; i++)
        arr[i] += (count * (i + 1))
                + (k * (count * (count - 1)) / 2);
 
 	Result r;
    
    for (int i = 0; i < k; i++)
        r.output1[i] = arr[i];

    return r;
}
 
int main()
{
    int n = 7, k = 4;
    Result R = toffees(n, k);
    for(int i=0;i<4;i++) cout<<R.output1[i]<<" ";
 
    return 0;
}