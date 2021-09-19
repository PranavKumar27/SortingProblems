#include <iostream>
#include <vector>

using namespace std;

// Coded on Sept 19, 2021 @Pranav
// Quick Sort Alogorithm
// Based on Divide and Conquer Algo
// Pivot Element is the last element

void print_v(vector<int> v)
{
	for (auto u : v)
	{
		cout << u << ",";
	}
	cout << endl;
}

void _myswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int partition(vector<int> &v, int l, int r)
{
	int i, j;
	int s;
	int pivot = v[r];

	i = l - 1;

	for (j = l; j <= r; j++)
	{
		if (v[j] < pivot)
		{
			i++;
			swap(v[i], v[j]);
			//print_v(v);
		}
	}
	i++;
	swap(v[i], v[r]);
	//print_v(v);

	return i;
}

void QuickSort(vector<int> &v, int l, int r)
{
	// Base Case

	if (l >= r)
	{
		return;
	}

	int pivot = partition(v, l, r);
	QuickSort(v, l, pivot - 1);
	QuickSort(v, pivot + 1, r);
}

int main(int argc, char *argv[])
{
	vector<int> v = {10, 9, 8, 2, 3, 7, 6, 4, 1, 5};

	cout << "Before Sorting" << endl;
	print_v(v);

	QuickSort(v, 0, v.size() - 1);

	cout << "After Sorting" << endl;
	print_v(v);

	return 0;
}
