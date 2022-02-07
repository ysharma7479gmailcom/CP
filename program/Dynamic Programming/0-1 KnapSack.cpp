//0-1 knapsack

#include<bits/stdc++.h>
using namespace std;
int dp1[100][100];
int knap_sack_recur(int *w,int *v,int n,int W)
{
	if(W<=0)return 0;
	if(n<=0)return 0;
	
	int t1=0,t2=0;
	
	if(W-w[n-1]<0)
		return knap_sack_recur(w,v,n-1,W);
	else 
		return max(v[n-1]+knap_sack_recur(w,v,n-1,W-w[n-1]) , knap_sack_recur(w,v,n-1,W));
}
//top to bottom
int top_dynamic(int *w,int *v,int n,int W)
{
	if(W<=0)return 0;
	if(n<=0)
		return 0;
	if(dp1[n][W]==0)
	{
		if(W-w[n-1]<0)
		dp1[n][W]= knap_sack_recur(w,v,n-1,W);
	else 
		dp1[n][W]= max(v[n-1]+knap_sack_recur(w,v,n-1,W-w[n-1]) , knap_sack_recur(w,v,n-1,W));
	}
	
	return dp1[n][W];
}
//bottom
int bottom_dynamic(int *w,int *v,int n,int W)
{
	int dp[n+1][W+1];
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			if(i==0)dp[i][j]=0;
			else if(w[i-1]>j)
				dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
		}
	}
	return dp[n][W];
}
int main()
{
	int n,W;
	cin>>n>>W;
	int *w=new int[n];
	int *v=new int[n];
	
	for(int i=0;i<n;i++)cin>>w[i];
	for(int i=0;i<n;i++)cin>>v[i];
	
	cout<<knap_sack_recur(w,v,n,W)<<endl;
	
	cout<<bottom_dynamic(w,v,n,W)<<endl;
	cout<<top_dynamic(w,v,n,W)<<endl;
}
