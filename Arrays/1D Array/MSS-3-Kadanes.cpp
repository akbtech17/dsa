// MSM - 3.cpp
#include <iostream>
using namespace std;

//tc n
//sc 1
void kadanes(int *arr, int n) {
	int curr_sum;
	int overall_sum;

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			curr_sum = overall_sum = arr[i];
			continue;
		}
		/*agar peeche se sum pos
		ara hai toh max contribute krne ke liye
		element usi me add hojayga*/
		if (curr_sum >= 0) curr_sum += arr[i];
		/*nhi toh apni nyi train bna lega, kahega maa chuday sab
		mai nayi train bna rha*/
		else curr_sum = arr[i];
		overall_sum = max(overall_sum, curr_sum);
	}
	cout << "Max Subarray Sum is : " << overall_sum ;
	return;
}


int main() {
	int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr) / sizeof(int);

	kadanes(arr, n);

	return 0;
}