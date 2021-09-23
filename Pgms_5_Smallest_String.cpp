#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Coded on Sept 23, 2021 @Pranav
// Find smallest string formed from list of strings
// which is lexicographically smallest
// Eg:
// Input as
// a, ab, aba
// Result= aabaab
// Result is lexicographically smallest from all posibilities

void print_v(vector<string> v)
{
	for (auto rr : v)
	{
		cout << rr << " ";
	}
	cout << endl;
}
void merge(vector<string> &v, int l, int r)
{
	int i, j;
	int mid;

	print_v(v);
	vector<string> temp;

	mid = (l + r) / 2;
	i = l;
	j = mid + 1;

	while (i <= mid && j <= r)
	{
		string str1 = "";
		string str2 = "";
		str1 += v[i] + v[j];
		str2 += v[j] + v[i];
		//cout << "DBG >> " << " str1=" << str1 << " str2=" << str2 << endl;
		int val = str1.compare(str2);
		//cout << "str1.compare(str2) =" << val << endl;
		if (val <= 0)
		{
			temp.push_back(v[i]);
			i++;
			print_v(temp);
		}
		else if (val > 0)
		{
			temp.push_back(v[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		temp.push_back(v[i]);
		i++;
	}

	while (j <= r)
	{
		temp.push_back(v[j]);
		j++;
	}

	print_v(temp);
	// Copy back from temp to v
	int k = 0;

	for (int idx = l; idx <= r; idx++)
	{
		v[idx] = temp[k];
		k++;
	}
}
void findSmallestString(vector<string> &v, int l, int r)
{
	int mid;
	mid = (l + r) / 2;

	if (l >= r)
	{
		return;
	}

	findSmallestString(v, l, mid);
	findSmallestString(v, mid + 1, r);
	merge(v, l, r);
}

string &concat_str(vector<string> v)
{
	string result = "";
	for (auto g : v)
	{
		result += g;
	}
	return result;
}
int main(int argc, char *argv[])
{
	vector<string> v = {"a", "ab", "aba", "aa"};

	cout << "DBG>> "
		 << "Before Sorting.." << endl;
	print_v(v);
	findSmallestString(v, 0, v.size() - 1);

	cout << "DBG>> "
		 << "After Sorting.." << endl;
	print_v(v);

	string Res = concat_str(v);
	cout << "Result= " << Res << endl;

	return 0;
}
