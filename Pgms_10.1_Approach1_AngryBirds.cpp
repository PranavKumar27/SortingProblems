#include <iostream>
#include <vector>

// Coded on Oct 28th, 2021.
// Angry Birds
// For a given N number of Nests for B number of Birds
// Find the smallest distance such that Birds are placed in Nest are least angry
// The closer the birds are placed in Nests, they would be more angrier.
// The farthest the birds are placed in Nests, they would be least angrier.
// eg:
// N= 5, B=3 
// Nests= [1,2,4,8,9]
// OP = 3
// If birds are placed in nest as below
// 2 4 8 birds are angry . Minimum distance = 4-2= 2, So angrier here
// 1 4 8 birds are least angry , Minimum distance = 4-1 =3

// Approach 1: Use brute Force with all combinations
// to select B Nests out of N Nests such that distance is max and birds are least angry
// N-C-B combinations

// Approach 2:  Divide the distance in number line
// If only two birds place at start and end and ans is obtained
// If more than 2, find mid of the distance
// Now try to place to Birds in Nest such that distance >=mid, if possible
// PART 1 :Go to right and find new mid, where s=mid+1 such that
// birds can be placed in Nest such that distance >= new mid
// PART 2: Anything to the left of mid is not useful as we look for maximum distance
// Once birds can be fitted using PART 1: mid will be the ans- mimimum possible separate
// among birds which is optimized.

// Below code implements Approach 1

#include<iostream>
#include<vector>

using namespace std;

void print_ncr(vector<int> v,int r);
void callNcrUtils(vector<int> v,int res[],int s,int e,int index,int r);
void print_v(vector<int>v);
void print_a(int arr[],int sz);
void processNcrSet(int);
bool cmp(int,int);
vector < vector<int> > NcrSet;
vector<int> allMinimums;

int main(int argc, char *argv[])
{
	vector<int> v={1,2,4,8,9};
	int r=3;
	// Find all nCr values i.e. 5c3
	
	print_ncr(v,r);
	
	processNcrSet(r);
	
	sort(allMinimums.begin(),allMinimums.end(),cmp);
	
	cout << "Result=" << allMinimums[0] << endl;
	return 0;	
}

bool cmp(int a,int b)
{
	if(a>b)
		return true;
	else 
		return false;
}
void print_ncr(vector<int> v,int r)
{
	int res[r];
	int n=v.size();
	//cout << "callNcrUtils(" << 0 << "," << n-1 << "," << 0 << "," << r << ")" << endl;
	callNcrUtils(v,res,0,n-1,0,r);	
}


void callNcrUtils(vector<int> v,int res[],int s,int e,int index,int r)
{
	int i,j;

	if(index==r)
	{
		print_a(res,r);
		
		return;
	}
	for(i=s; i <= e && e-i+1 >= r-index;i++)
	{
		res[index]=v[i];
		//cout << "callNcrUtils(" << i+1 << "," << e << "," << index+1 << "," << r << ")" << endl;
		callNcrUtils(v,res,i+1,e,index+1,r);
	}
}

void print_v(vector<int> v)
{
	for(auto a:v)
	{
		cout << a << " ";
	}
	cout << endl;
}
void print_a(int arr[],int sz)
{
	vector<int> ss;
	int i=0;
	for(i=0;i<sz;i++)
	{
		//cout << arr[i] << " ";
		ss.push_back(arr[i]);
	}
	NcrSet.push_back(ss);
}

void processNcrSet(int r)
{
	int minimum;
	int i,val;
	for(auto x:NcrSet)
	{
		// Consider r is always > 2
		minimum=x[1]-x[0];
		for(i=2;i<r;i++)
		{
			val=x[i]-x[i-1];
			minimum = min(val,minimum);
		}
		allMinimums.push_back(minimum);
	}	
}
