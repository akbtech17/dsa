#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[100005];
	for ( int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int q;
	cin >> q;
	int money, K;
	while (q--)
	{
		cin >> money >> K;
		int count = 0;
		for ( int i = 0; i < n; i++)
		{
			if (money % arr[i] == 0)
			{
				count++;
			}
		}
		if (count >= K)
		{
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}