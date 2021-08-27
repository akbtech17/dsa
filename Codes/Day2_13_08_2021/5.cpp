// 5.cpp

#include <bits/stdc++.h>
#include <vector>
using namespace std;

  int MissingMarbles(int number, int bowls[]){
           int sum = bowls[0] + bowls[number - 1];
           // cout<<"sum"<<sum;
           int missing = 0;
           int i = 1, j = number - 2;
           while(i<=j)
           {
               if(bowls[i]+bowls[j] == sum){  
                   i++;  
                   j--;  
               }
               else {
                   if (i == j) missing = sum - bowls[i];
                   // missing = (sum - (bowls[i] + bowls[j]));
                    else {
                        if(bowls[i+1] + bowls[j] == sum) {
                            missing = sum - bowls[i];
                        }
                        else {
                            missing = sum - bowls[j];
                        }
                    }
                   break;
               }
           }
           return missing;
       }

int main() {
    int arr[] = {1,5,7,9,11};
    int n = 5;
    cout<<MissingMarbles(n,arr);
    return 0;
}