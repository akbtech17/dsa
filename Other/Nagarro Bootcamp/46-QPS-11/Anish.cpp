// Anish.cpp
#include<bits/stdc++.h>
using namespace std;

int lds(int input1, int input2[])
{
	int n = input1;
	int *arr = input2;
    int lds[n];
    int i, j, max = 0;
 
    for (i = 0; i < n; i++)
        lds[i] = 1;
 
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
 
   
    for (i = 0; i < n; i++)
        if (max < lds[i])
            max = lds[i];
 
    return max;
}
// Driver Code
int main()
{
    int arr[] = { 1,3,2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of LDS is " << lds(n,arr);
    return 0;
}