// Created on Sept 20, 2021,
// Author Pranav

#inclu de < iostream >
#include <vector>

using namespace std;

//Implement Merge Sort

void print_v(vector<int> v)
{
	for (auto d : v)
	{
		cout << d << ",";
	}
	cout << endl;
}

void Merge(vector<int> &v, int l, int r)
{
	vector<int> v_temp;
	int i, j;

	int mid = (l + r) / 2;

	i = l;
	j = mid + 1;

	while (i <= mid && j <= r)
	{
		if (v[i] < v[j])
		{
			v_temp.push_back(v[i]);
			i++;
		}

		else if (v[i] > v[j])
		{
			v_temp.push_back(v[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		v_temp.push_back(v[i]);
		i++;
	}

	while (j <= r)
	{
		v_temp.push_back(v[j]);
		j++;
	}

	// copy from temp
	int k = 0;

	for (int idx = l; idx <= r; idx++)
	{
		v[idx] = v_temp[k++];
	}
}

void MergeSort(vector<int> &v, int l, int r)
{
	int mid = (l + r) / 2;
	int i, j;
	if (l >= r)
	{
		return;
	}

	MergeSort(v, l, mid);
	MergeSort(v, mid + 1, r);
	Merge(v, l, r);
}

int main(int argc, char *argv[])
{
	vector<int> v = {4, 3, 2, 1};

	cout << "Before Merge Sort" << endl;
	print_v(v);

	MergeSort(v, 0, v.size() - 1);

	cout << "After Merge Sort" << endl;
	print_v(v);

	return 0;
}
