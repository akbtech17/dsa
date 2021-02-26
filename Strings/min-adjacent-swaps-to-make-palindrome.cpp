// min - adjacent - swaps - to - make - palindrome.cpp
#include<iostream>
#include <string>
using namespace std;



int minSwapsPalindrome(string str) {
	int ans = 0;
	int len = str.length();
	//take to pointer, s = left and e = right of the string
	for (int left = 0; left < len / 2; ++left)
	{
		int right = len - left - 1;
		//if char at left != right
		if (str[left] != str[right]) {
			while (left < right) {
				if (str[right] != str[left]) right--;
				else break;
			}

			if (right == left) return -1;
			ans += right - (len - left - 1);
			for (int j = right; j <= len - left - 1; ++j)
				swap(str[j], str[j + 1]);

		}

	}


	return ans;
}

int main() {
	string str;
	cin >> str;
	cout << min(minSwapsPalindrome(str), minSwapsPalindrome(strrev(str));
	            return 0;
}

