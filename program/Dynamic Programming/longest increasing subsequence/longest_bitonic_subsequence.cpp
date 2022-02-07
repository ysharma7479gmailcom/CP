#include<bits/stdc++.h>
using namespace std;
vector<int> lis[100];
vector<int> lds[100];

void increasing(int a[],int n)
{
	lis[0].push_back(a[0]);
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j] && lis[j].size() >= lis[i].size())
				lis[i]=lis[j];
		}
		lis[i].push_back(a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<lis[i].size();j++)
		cout<<lis[i][j]<<" ";
	cout<<endl;
	}
	cout<<endl;
}

void decreasing(int a[],int n)
{
	lds[n-1].push_back(a[n-1]);
	
	for(int i=n-2;i>-1;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[i]>a[j] && lis[j].size() >= lds[i].size())
				lds[i]=lds[j];
		}
		lds[i].push_back(a[i]);
	}
	
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<lds[i].size();j++)
		cout<<lds[i][j]<<" ";
	cout<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	increasing(a,n);
	decreasing(a,n);
	
	int m=0,j;
	for(int i=0;i<n;i++)
	if(m<(lis[i].size()+lds[i].size()))
	{
		m=lis[i].size()+lds[i].size();
	}
	
	for(int i=0;i<n;i++)
	{
	if(m==(lis[i].size()+lds[i].size()))
	{
		for(int j=0;j<lis[i].size();j++)
		cout<<lis[i][j]<<" ";
		reverse(lds[i].begin(),lds[i].end());
		for(int j=1;j<lds[i].size();j++)
		cout<<lds[i][j]<<" ";
		
			cout<<endl;	
	}
	cout<<endl;	
	}
}
