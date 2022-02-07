#include<bits/stdc++.h>
using namespace std;

int subset_sum(int *a,int n,int s)
{
	if(s==0) return 1;
	if(n<0 || s<0)return 0;
	
	return subset_sum(a,n-1,s) || subset_sum(a,n-1,s-a[n-1]);
}


int main()
{
	int n,s;
	cin>>n>>s;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	//coin change type
	cout<<subset_sum(a,n,s)<<endl;
}
