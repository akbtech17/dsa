// missing - number.cpp
#include <iostream>
using namespace std;


//Approach 1
//Find the sum of N numbers and subtract the given numbers from it
//it will result to ans

//Approach 2
//TC = N
//SC = 1
int main() {
	int n, no;

	//input the total number of Natural Numbers
	cin >> n;

	int exp1 = 0, exp2 = 0;

	//taking xor of input numbers
	for (int i = 1; i < n; i++) {
		cin >> no;
		exp1 ^= no;
	}

	//taking xor of all N natural numbers
	for (int i = 1; i <= n; i++) {
		exp2 ^= i;
	}

	//print the missing number
	cout << (exp1 ^ exp2) << endl;

	return 0;
}