// 6.cpp



#include <bits/stdc++.h>
#include <vector>
using namespace std;
int longestCommonPrefix(string ar[], int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return ar[0].size();
    sort(ar, ar + n);
    int en = min(ar[0].size(),
                 ar[n - 1].size());
    string first = ar[0], last = ar[n - 1];
    int i = 0;
    while (i < en && first[i] == last[i])
        i++;
    string pre = first.substr(0, i);
    return pre.size();
}
 
// Driver Code
int main()
{
    string ar[] = {"this","that","there"};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << longestCommonPrefix(ar, n);
    return 0;
}
