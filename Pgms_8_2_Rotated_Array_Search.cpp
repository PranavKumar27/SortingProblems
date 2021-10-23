#include <iostream>
#include <vector>

using namespace std;
// Coded by @Pranav on Oct 23, 2021
// On a sorted array which is rotated about a pivot,
// Find the index for the occurence of K
// 4,5,6,7,0,1,2,3 -> Rotated Sorted Array
// Pivot is 0
// Find K=6, Result=2.
// Approach 1: Run a linear search
// Approach 2: Find the pivot, decide and run binary search on
// one part of the pivot
// Approach 3: Find mid and check whether item belongs to left Line or right Line
// If it belongs to left, a[s] <=K -> Item belongs to left line
// Now decide whether to search onto left part of right part of left line
// if a[s]<=K <=a[mid] --> search onto left part of left line
// if a[mid+1]<=K<=a[e]-->search onto right part of left line+ right line
// Perform Similar thing if item belong to right line
// If K<=a[e] --> Item falls on the right line
// Approach 3 is implemented below

int findIndexOfK(vector<int> v, int s, int e, int K)
{
	int ans = -1;
	int mid;

	while (s <= e)
	{
		mid = (s + e) / 2;
		cout << "s=" << s << " e=" << e << " mid= " << mid << endl;
		if (v[mid] == K)
		{
			cout << "mid=" << mid << "  v[mid]=" << v[mid] << " K=" << K << endl;
			ans = mid;
			return mid;
		}
		else if (v[s] <= v[mid])
		{
			// Left line contains K
			//cout << "On Left Line" <<  endl;
			//cout << "Before s=" << s << " e=" << e << " mid=" << mid << endl;

			if (v[s] <= K && K <= v[mid])
			{
				// Left Part of Left line
				e = mid - 1;
			}
			else
			{
				s = mid + 1;
			}
		}
		else if (v[mid] <= v[e])
		{
			if (v[mid] <= K && K <= v[e])
			{
				// Left Part of Left line
				s = mid + 1;
			}
			else
			{
				e = mid - 1;
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[])
{
	vector<int> v = {4, 5, 6, 7,0, 1, 2, 3};
	int K = 4;
	int index, i, j, k;

	index = findIndexOfK(v, 0, v.size() - 1, K);

	cout << "Result=" << index << endl;

	return 0;
}
