// pascal - triangle.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[10][10] = {0};
	for (int i = 0; i < n; ++i)
	{
		//spaces
		for (int spaces = 1; spaces <= n - i ; ++spaces)
			cout << " ";
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 or j == n - 1) arr[i][j] = 1;
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}