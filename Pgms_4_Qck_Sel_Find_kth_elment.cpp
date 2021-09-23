#include <iostream>
#include <vector>

using namespace std;

//Coded on Sept 23, 2021 @Pranav
//Find the K-th smallest element
// from the given Array

static int ans = -1;
void print_v(vector<int> v);
int partition(vector<int> &v, int l, int r)
{
	int i, j;

	int pivot = v[r];
	i = l - 1;
	j = l;
	while (j < r)
	{
		if (v[j] > pivot)
		{
			// no problem
			j++;
		}
		else if (v[j] < pivot)
		{
			i++;
			swap(v[i], v[j]);
			j++;
		}
	}

	i++;
	swap(v[i], v[r]);
	//cout << "DBG " <<" l=" << l << "  r=" << r << " pivot=" << pivot << endl;
	//print_v(v);
	return i; // pivot correct postional index
}

void QuickSelect(vector<int> &v, int l, int r, int k)
{
	int pivot;

	pivot = partition(v, l, r);

	if (pivot == k - 1)
	{
		//cout << "DBG " << "Found kth value= " << v[pivot] << endl;
		//cout << "DBG " << "Found index=" << pivot << endl;
		ans = v[pivot];
	}

	if (l >= r)
	{
		return;
	}

	else if (pivot < k)
	{
		QuickSelect(v, pivot + 1, r, k);
	}

	else
	{
		QuickSelect(v, l, pivot - 1, k);
	}
}

void print_v(vector<int> v)
{
	for (auto z : v)
	{
		cout << z << ",";
	}
	cout << endl;
}
int main(int argc, char *argv[])
{
	vector<int> v = {10, 5, 2, 0, 6, 4};
	int k;

	cout << "Enter K:";
	cin >> k;

	cout << "Vector v=" << endl;
	print_v(v);
	cout << "Sorted Vector=" << endl;
	vector<int> v_cpy(v.begin(), v.end());
	sort(v_cpy.begin(), v_cpy.end());
	print_v(v_cpy);

	if (k > v.size())
	{
		cout << "Plese Enter Valid K" << endl;
	}
	else
	{
		QuickSelect(v, 0, v.size() - 1, k);

		cout << "Result=" << ans << endl;
	}
	return 0;
}
