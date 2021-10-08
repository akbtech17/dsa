// extract - number - from - string.cpp
//we have to extract the largest possible number from string
//which doesnt contain 9 as a digit in it
#include <iostream>
#include <string>
#define ll long long
using namespace std;

string extractLargestNumber(string str) {
	string ans;
	ll num = 0;
	bool is_ans_possible = false;
	for (int i = 0; i < str.length();) {
		if (str[i] >= '0' and str[i] <= '9') {
			//extract the number
			string temp;
			bool contain_nine = false;
			while (i<str.length() and str[i] >= '0' and str[i] <= '9') {
				if (str[i] == '9') contain_nine = true;
				temp.push_back(str[i]);
				i++;
			}
			if (!contain_nine) {
				is_ans_possible = true;
				ll temp_num = stol(temp);
				if (temp_num > num) {
					num = temp_num;
					ans = temp;
				}
			}
		}
		else {
			i++;
		}
	}
	if (!is_ans_possible) return "Not Possible";
	return ans;
}

int main() {
	string str;
	getline(cin, str);

	cout << extractLargestNumber(str);

	return 0;
}