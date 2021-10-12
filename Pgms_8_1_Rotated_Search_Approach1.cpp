#include <iostream>
#include <vector>

using namespace std;
// Coded by @Pranav on Oct 12, 2021
// On a sorted array which is rotated about a pivot,
// Find the index for the occurence of K
// 4,5,6,7,0,1,2,3 -> Rotated Sorted Array
// Pivot is 0
// Find K=6, Result=2.
// Approach 1: Run a linear search
// Approach 2: Find the pivot, decide and run binary search on
// one part of the pivot
// Approach 3:TODO

int BinSrch(vector<int> v, int s, int e, int K)
{
	int mid;
	while (s <= e)
	{
		mid = (s + e) / 2;

		if (v[mid] == K)
		{
			return mid;
		}

		else if (v[mid] < K)
		{
			s = mid + 1;
		}

		else if (v[mid] > K)
		{
			e = mid - 1;
		}
	}
	return -1;
}
int findPivot(vector<int> v)
{
	int i;
	for (i = 0; i < v.size() - 1; i++)
	{
		if (v[i] <= v[i + 1])
		{
			continue;
		}
		else
		{
			return i + 1;
		}
	}
	return -1;
}
int main(int argc, char *argv[])
{
	vector<int> v = {4, 5, 6, 7, 0, 1, 2, 3};
	int K = 7;
	int index, i, j, k;
	// Find pivot index
	index = findPivot(v);
	if (index == -1)
	{
		cout << "Not Rotated" << endl;
	}
	else
	{
		cout << "Rotated at index :" << index << " value=" << v[index] << endl;
	}

	// Decide whether to search on Left/right array
	int ans_idx = -1;
	if (v[0] <= K && K <= v[index - 1])
	{
		// Perform Bin Search onto Left array
		ans_idx = BinSrch(v, 0, index - 1, K);
	}
	int sz = v.size();
	cout << "Value at sz-1=" << v[sz - 1] << endl;
	if (v[index] <= K && K <= v[sz - 1])
	{
		// Perform Bin Search onto Right array
		ans_idx = BinSrch(v, index, v.size() - 1, K);
	}

	if (ans_idx != -1)
		cout << "Result=" << ans_idx << endl;
	else
		cout << "Value not found" << endl;

	return 0;
}
