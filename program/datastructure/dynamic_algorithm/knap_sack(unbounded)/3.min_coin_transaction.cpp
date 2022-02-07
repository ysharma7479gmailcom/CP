#include<bits/stdc++.h>
using namespace std;
//short trick 1d array
int coin_change(int v[],int n,int s)
{
	int max=s+1;
	vector<int> dp(s+1,max);
	dp[0]=0;
	for(int i=1;i<=s;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(v[j]<=i)
				dp[i]=min(dp[i],dp[i-v[j]]+1);
		}	
	}	 
	return dp[s]>s?-1:dp[s];
}

//2 d array
int coin_change1(int v[],int n,int s)
{
	
}
int main()
{
	int n;
	cin>>n;
	int v[n];
	
	for(int i=0;i<n;i++)cin>>v[i];
	
	int w;
	cin>>w;
	
	cout<<coin_change(v,n,w);
	
}
