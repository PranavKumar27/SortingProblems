#include<iostream>
#include<vector>

using namespace std;

void print_ncr(vector<int> v,int r);
void callNcrUtils(vector<int> v,int res[],int s,int e,int index,int r);
void print_v(vector<int>v);
void print_a(int arr[],int sz);


int main(int argc, char *argv[])
{
	vector<int> v={1,2,3,4,5};
	int r=3;
	// Find all nCr values i.e. 5c3
	
	print_ncr(v,r);
	
	return 0;	
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
	int i=0;
	for(i=0;i<sz;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
