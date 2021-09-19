#include<iostream>
#include<vector>
#include <vector>
#include <utility>

// Coded On Sept 19,2021 by Pranav
// Inversion Count
// 0 5 2 3 1
// Inversion is such that arr[i] > arr[j] such that i<j
// such pairs are:
// (5,2) (5,3) (5,1)  (2,1) (3,1)
// Result = 5
// The below solution is a Brute Force Approach

using namespace std;

void print_vp(vector<pair<int,int>> yy)
{
	for(auto idx:yy)
	{
		cout << idx.first <<	"," << idx.second <<  endl;
	}
}

int findInversionCount(vector<int> v)
{
	int i,j;
	int count=0;
	vector<pair<int,int>> vp;
	for(i=0;i<v.size();i++)
	{
		for(j=i+1;j<v.size();j++)
		{
			if(v[i]>v[j])
			{
				count++;
				pair<int,int> p={v[i],v[j]};
				vp.push_back(p);
			}
		} // end of for j
	} // end of for i
	
	// print vector of pairs
	
	cout << "Vector Pairs" << endl;
	print_vp(vp);
	return count;
}


int main(int argc, char *argv[])
{
	vector<int> v={0,5,2,3,1};
	
	int ans=findInversionCount(v);
	cout << "Result=" << ans << endl;
	return 0;
}


	
