#include <iostream>
#include <string.h>
#include <climits>
using namespace std;

int kadanesSum(int *arr, int n) {
	int curr_sum;
	int overall_sum;

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			curr_sum = overall_sum = arr[i];
			continue;
		}
		if (curr_sum >= 0) curr_sum += arr[i];
		else curr_sum = arr[i];
		overall_sum = max(overall_sum, curr_sum);
	}
	return overall_sum;
}


int main() {
	int row, col;
	cin >> row >> col;
	int arr[row][col];
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int temp[row] = {0};
	int max_sum_so_far = INT_MIN;

	for (int left = 0; left < col; ++left)
	{
		memset(temp, 0, sizeof(temp));
		for (int right = left; right < col; ++right)
		{
			for (int ith_row = 0; ith_row < row; ++ith_row)
			{
				temp[ith_row] += arr[ith_row][right];
			}
			int curr_sum = kadanesSum(temp, row);
			max_sum_so_far = max(max_sum_so_far, curr_sum);
		}
	}
	cout << max_sum_so_far;

	return 0;
}