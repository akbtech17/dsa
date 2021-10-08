// 5-MultiplyTwoStrings.cpp
#include<iostream>
#include<string>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;


  		//    1 2 3 
	 	//  X   4 5
		// ---------------	  			
		// 	    1 5
		// 	  1 0
		//  0 5
		// ---------------
		// 	  1 2
		//  0 8		 
		// 0 4   
		// ----------------
		// 0 5 5 3 5



string multiply(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();

	// when we multiply n,m digit number
	// result may have atmost n+m digits

	string out(len1+len2,'0');

	// if we multipy
	// num1 jth idx
	// num2 ith idx
	// then it will affect indexes, i+j and i+j+1

	for(int i=len1-1; i>=0; i--){
		for(int j=len2-1; j>=0; j--){
			int prod = (num1[i]-'0') * (num2[j]-'0');
			int pos1 = i+j;
			int pos2 = i+j+1;

			int sum = (out[pos2]-'0') + prod;
			out[pos2] = (sum%10)+'0';
			out[pos1] = (out[pos1]-'0')+(sum/10)+'0';

		}	
	}

	// removing leading zeroes
	size_t startPos = out.find_first_not_of('0');
	return startPos == string::npos	? "0" : out.substr(startPos); 

	
	return out;
}


int main() {
	string num1 = "0", num2 = "0";
	cout<<multiply(num1,num2)<<endl;
	return 0;
}