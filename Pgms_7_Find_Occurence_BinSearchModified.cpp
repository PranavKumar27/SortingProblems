#include<iostream>
#include<vector>

using namespace std;

//Coded By @Pranav on 3rd Oct
// On a sorted vector, find the number of occurence of K element
// Approach 1: Using Linear serach, find First and Last occurrence,
// Then total occur=last occur-first occur +1
// Approach 2: Using binary search


int myBinSrch(vector<int> v,int s, int e,int K)
{
	int mid;
	while(s<=e)
	{
		mid=(s+e)/2;
		
		if(v[mid]==K)
		{
			return mid;
		}
		else if(v[mid]>K)
		{
			e=mid-1;
		}
		
		else if(v[mid]<K)
		{
			s=mid+1;
		}
		
	}
	return -1;
}


int findLowIdx(vector<int> v,int s,int e,int K)
{
	int index;
	int ans=-1;
	do
	{
		index=myBinSrch(v,s,e,K);
		if(index!=-1)
		{
			ans=index;
			e=index-1;
		}
		
	}while(index!=-1);
	
	return ans;
}


int findHighIdx(vector<int> v,int s,int e,int K)
{
	int index;
	int ans=-1;
	do
	{
		index=myBinSrch(v,s,e,K);
		if(index!=-1)
		{
			ans=index;
			s=index+1;
		}
	}while(index!=-1);
	
	return ans;
}

int main(int argc, char *argv[])
{
	vector<int> v ={1,1,2,2,2,3,3,4,4,4,4,5,5,5,9,9};
	int k=1;
	int idx,low_idx,high_idx;
	int result;
	
	idx=myBinSrch(v,0,v.size()-1,k);
	
	//cout << "idx=" << idx << endl;
	
	low_idx=findLowIdx(v,0,idx-1,k);
	if(low_idx==-1)
	{
		low_idx=idx;
	}
	//cout << "low_idx=" << low_idx << endl;
	
	high_idx=findHighIdx(v,idx+1,v.size()-1,k);
	if(high_idx==-1)
	{
		high_idx=idx;
	}
	//cout << "high_idx=" << high_idx << endl;
	
	
	result=high_idx-low_idx+1;
	
	cout << "Result=" << result << endl;
		
	return 0;
}

