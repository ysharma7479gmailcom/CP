#include<bits/stdc++.h>
using namespace std;

int unbounded_knapsack(int v[],int wt[],int w,int n)
{
	int t[n+1][w+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0 || j==0)t[i][j]=0;
		else if(wt[i-1]<=j)
				t[i][j]=max(v[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
				
		}
	}
	return t[n][w];
}
int main()
{
	int n;
	cin>>n;
	int v[n],wt[n];
	
	for(int i=0;i<n;i++)cin>>v[i];
	
	for(int i=0;i<n;i++)wt[i]=i+1;
	
	
	cout<<unbounded_knapsack(v,wt,n,n);
	
}
