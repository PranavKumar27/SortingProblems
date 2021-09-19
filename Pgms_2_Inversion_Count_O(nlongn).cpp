#include<iostream>
#include<vector>

using namespace std;

// Coded On Sept 19,2021 by Pranav
// Inversion Count
// 0 5 2 3 1
// Inversion is such that arr[i] > arr[j] such that i<j
// such pairs are:
// (5,2) (5,3) (5,1)  (2,1) (3,1)
// Result = 5
// The below solution is a based on D&C in O(nlogn) Approach

static int total=0;

void print_v(vector<int> v)
{
	for (auto d : v)
	{
		cout << d << ",";
	}
	cout << endl;
}

void InversionTotal(vector<int> &v,int l, int r)
{
	cout << "Count=" << total << endl;
	int i,j,mid;
	vector<int> temp;
	
	mid=(l+r)/2;
	
	i=l;
	j=mid+1;
	
	while(i<=mid && j<=r)
	{
		if(v[i]<=v[j])
		{
			temp.push_back(v[i]);
			i++;
			// no problem
		}
		else
		{
			total=total+mid-i+1;
			temp.push_back(v[j]);
			j++;
		}
	} // end of while
	
	while(i<=mid)
	{
		temp.push_back(v[i]);
		i++;
	}
	
	while(j<=r)
	{
		temp.push_back(v[j]);
		j++;
	}

	// updating back v
	int k=0;
	for(int idx=l;idx<=r;idx++)
	{
		v[idx]=temp[k++];
	}
	print_v(v);

}

void findInversionCount(vector<int> &v,int l,int r)
{
	int i,j,mid;
	
	 mid=(l+r)/2;
	 
	 if(l>=r)
	 {
	  	return;
	 }
	  findInversionCount(v,l,mid);
	  findInversionCount(v,mid+1,r);
	  InversionTotal(v,l,r); 
}


int main(int argc, char *argv[])
{
	vector<int> v={0,5,2,3,1};
	
	findInversionCount(v,0,v.size()-1);
	
	cout << "Result=" << total << endl;
	
	return 0;
}

