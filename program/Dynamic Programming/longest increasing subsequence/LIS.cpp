#include<bits/stdc++.h>
using namespace std;


int recur_lis(int a[],int i,int n,int prev)
{
	if(i==n)
		return 0;
	int excl=recur_lis(a,i+1,n,prev);
	int incl=0;
	
	if(a[i]>prev)
		 incl=1+recur_lis(a,i+1,n,a[i]);
	
	return max(excl,incl);
}

int lis(int a[],int n)
{
	vector<int> v(n,1);
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>=a[j])
				v[i]=max(v[i],v[j]+1);
		}
	}
	int m=0;
	for(int i=0;i<v.size();i++)
		m=max(m,v[i]);
	return m;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cout<<recur_lis(a,0,n,-1)<<endl;
	
	cout<<lis(a,n)<<endl;
}
