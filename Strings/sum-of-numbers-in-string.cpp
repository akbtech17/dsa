// sum - of - numbers - in - string.cpp
#include <iostream>
#include <string>
#define ll long long
using namespace std;

int stringToInteger(string str) {
	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		ans *= 10;
		int curr_dig = str[i] - '0';
		ans += curr_dig;
	}
	return ans;
}

int sumOfNumbers(string str) {
	int num = 0;
	int sum = 0;
	bool is_ans_possible = false;
	for (int i = 0; i < str.length();) {
		if ((str[i] >= '0' and str[i] <= '9' ) or (str[i] == '-')) {
			//extract the number
			string temp;
			bool isneg = false;
			if (str[i] == '-') {
				isneg = true;
				i++;
			}
			while (i<str.length() and str[i] >= '0' and str[i] <= '9') {

				temp.push_back(str[i]);
				i++;
			}
			int temp_num = stringToInteger(temp);
			if (isneg) temp_num *= -1;
			sum += temp_num;
		}


		else {
			i++;
		}
	}
	return sum;
}

int main() {
	string str;
	cin >> str;

	cout << sumOfNumbers(str);

	return 0;
}