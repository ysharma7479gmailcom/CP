#include<bits/stdc++.h>
using namespace std;

int shortest_path(int **mat,int m,int n)
{
	int dp[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=mat[i][j];
			if(i==0 && j==0);
			else if(i==0)
			{
				dp[i][j]=dp[i][j]+dp[i][j-1];
			}
			else if(j==0)
			{
				dp[i][j]=dp[i][j]+dp[i-1][j];
			}
			
			else dp[i][j]=dp[i][j]+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
			
		}
	}
	return dp[m-1][n-1];
}
int main()
{
	
	int n,m;
	cin>>m>>n;
	int **mat=new int*[m];
	for(int i=0;i<m;i++)
	{
		mat[i]=new int[n];
		for(int j=0;j<n;j++)
			cin>>mat[i][j];
	}
	
	cout<<shortest_path(mat,m,n);
}
