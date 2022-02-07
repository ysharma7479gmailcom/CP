#include<bits/stdc++.h>
using namespace std;

void print_lis(int a[],int n)
{
	vector<int> lis[n],sum(n);
	lis[0].push_back(a[0]);
	sum[0]=a[0];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i] && sum[j] > sum[i])
				{
					sum[i]=sum[j];
				lis[i]=lis[j];
				}
		}
		lis[i].push_back(a[i]);
		sum[i]=sum[i]+a[i];
	}
	
	int j=0;
	for(int i=1;i<n;i++)
	{
		if(sum[i]>sum[j])
		j=i;
	}
	for(int i=0;i<lis[j].size();i++)
	cout<<lis[j][i]<<" ";
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)cin>>a[i];
	
	print_lis(a,n);
}
