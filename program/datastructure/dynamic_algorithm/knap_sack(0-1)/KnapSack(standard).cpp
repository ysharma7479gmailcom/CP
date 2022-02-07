#include<bits/stdc++.h>
using namespace std;

//recur knapsack 0/1
int t1[1001][1001];
int recur_knap(int wt[],int v[],int w,int n)
{
	if(n==0 || w==0)return 0;
	
	if(wt[n-1]<=w)
		return max(v[n-1]+recur_knap(wt,v,w-wt[n-1],n-1),recur_knap(wt,v,w,n-1));
	else
	return recur_knap(wt,v,w-wt[n-1],n-1);
}

int top_knap(int wt[],int v[],int w,int n)
{
	if(n==0 || w==0)return 0;
	
	if(t1[n][w]!=-1)return t1[n][w];
	if(wt[n-1]<=w)
		return t1[n][w]=max(v[n-1]+recur_knap(wt,v,w-wt[n-1],n-1),recur_knap(wt,v,w,n-1));
	else
	return t1[n][w]=recur_knap(wt,v,w-wt[n-1],n-1);
}

int bottom(int wt[],int v[],int w,int n)
{
	int dp[n+1][w+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(wt[i-1]<=j)
				dp[i][j]=max(v[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			else dp[i][j]=dp[i-1][j];
	}
	return dp[n][w];
}

int main()
{
	int n;
	cin>>n;
	int wt[n],v[n];
	for(int i=0;i<n;i++)cin>>wt[i];
	for(int i=0;i<n;i++)cin>>v[i];
	int w;
	cin>>w;
	cout<<recur_knap(wt,v,w,n)<<endl;
	for(int i=0;i<=n;i++)
        for(int j=0;j<=w;j++)
            t1[i][j]=-1;
	cout<<top_knap(wt,v,w,n)<<endl;
	cout<<bottom(wt,v,w,n)<<endl;
}
