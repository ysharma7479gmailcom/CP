#include<bits/stdc++.h>
using namespace std;

void print_spiral(int **a,int n)
{
	int l=0,r=n-1,t=0,b=n-1;
	
	while(l<r || t<b)
	{
		if(t<=b)
		{
			for(int i=l;i<=r;i++)
			cout<<a[t][i]<<" ";
		}
		t++;
		if(l<=r)
		{
			for(int j=t;j<=b;j++)
			cout<<a[j][r]<<" ";
		}
		r--;
		
		if(t<=b)
		{
			for(int i=r;i>=l;i--)
			cout<<a[b][i]<<" ";	
		}
		b--;
		if(l<=r)
		{
			for(int i=b;i>=t;i--)
			cout<<a[i][l]<<" ";
		}
		l++;
		
	}
}
int main()
{
	int n;
	cin>>n;
	int **a=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];
		for(int j=0 ;j<n;j++)
			cin>>a[i][j];
	}
	
	print_spiral(a,n);
}
