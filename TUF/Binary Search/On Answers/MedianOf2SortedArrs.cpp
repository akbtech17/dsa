#include <iostream>
using namespace std;

// Approach1: Using Merged Sorted Array
class Solution1 {
public:
	// TC: O(N)
	// SC: O(N)
	vector<int> mergeTwoSortedLists(vector<int> &arr1, vector<int> &arr2) {
		vector<int> merged;
		int n1 = arr1.size(), n2 = arr2.size();
		int i1 = 0, i2 = 0;

		while (i1 < n1 && i2 < n2) {
			if (arr1[i1] <= arr2[i2]) {
				merged.push_back(arr1[i1]);
				i1++;
			} else {
				merged.push_back(arr2[i2]);
				i2++;
			}
		}

		while (i1 < n1)
			merged.push_back(arr1[i1++]);
		while (i2 < n2)
			merged.push_back(arr2[i2++]);

		return merged;
	}

	double median(vector<int> &arr1, vector<int> &arr2) {
		vector<int> mergedList = mergeTwoSortedLists(arr1, arr2);
		int ms = mergedList.size();

		// odd
		if (ms % 2) return mergedList[ms / 2];
		// even
		else {
			int mid = (ms / 2);
			double med = double(mergedList[mid - 1] + mergedList[mid]) / 2.0;
			return med;
		}
	}
};

// Approach2: Using Merged Sorted Array without storing the elements
class Solution2 {
public:
	// TC: O(N/2)
	// SC: O(1)
	double median(vector<int> &arr1, vector<int> &arr2) {
		int n1 = arr1.size(), n2 = arr2.size();
		int i1 = 0, i2 = 0, cnt = 0;

		bool noOfElementsOdd = (n1 + n2) % 2;
		int idx1 = (n1 + n2) / 2;
		int idx2 = idx1 - 1;
		int el1, el2;

		while (i1 < n1 && i2 < n2 && cnt <= idx1) {
			if (arr1[i1] <= arr2[i2]) {
				if (cnt == idx1) el1 = arr1[i1];
				if (cnt == idx2) el2 = arr1[i1];
				i1++;
			} else {
				if (cnt == idx1) el1 = arr2[i2];
				if (cnt == idx2) el2 = arr2[i2];
				i2++;
			}
			cnt++;
		}

		while (i1 < n1 && cnt <= idx1) {
			if (cnt == idx1) el1 = arr1[i1];
			if (cnt == idx2) el2 = arr1[i1];
			i1++;
			cnt++;
		}

		while (i2 < n2 && cnt <= idx1) {
			if (cnt == idx1) el1 = arr2[i2];
			if (cnt == idx2) el2 = arr2[i2];
			i2++;
			cnt++;
		}

		if (noOfElementsOdd) return el1;
		return (double)(el1 + el2) / 2.0;
	}
};

// Approach3: Using BS
class Solution3 {
public:
	// TC: O(Log(min(N1, N2)))
	// SC: O(1)
	double median(vector<int> &arr1, vector<int> &arr2) {
		int n1 = arr1.size(), n2 = arr2.size();
		int ts = n1 + n2, ms = (n1 + n2) / 2;

		if (n1 > n2) return median(arr2, arr1);

		int s = 0, e = n1;
		while (s <= e) {
			int m = s + (e - s) / 2;
			int cnt1 = m;
			int cnt2 = ms - cnt1;

			int l1 = (cnt1 == 0) ? INT_MIN : arr1[cnt1 - 1];
			int l2 = (cnt2 == 0) ? INT_MIN : arr2[cnt2 - 1];
			int r1 = (cnt1 == n1) ? INT_MAX : arr1[cnt1];
			int r2 = (cnt2 == n2) ? INT_MAX : arr2[cnt2];

			if (l1 > r2) {
				e = m - 1;
			} else if (r1 < l2) {
				s = m + 1;
			} else {
				if (ts % 2) return min(r1, r2);
				return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
			}
		}

		return 0;
	}
};