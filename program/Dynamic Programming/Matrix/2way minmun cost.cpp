#include<bits/stdc++.h>
using namespace std;

int recur_min_cost(int **mat,int m,int n)
{
	if(m==0 || n==0)
	return INT_MAX;
	
	if(m==1 && n==1)
		return mat[0][0];
	
	else return min(recur_min_cost(mat,m-1,n),recur_min_cost(mat,m,n-1))+mat[m-1][n-1];
}

int dynamic_min_cost(int **mat,int m,int n)
{
	int dp[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=mat[i][j];
			if(i==0 && j>0)
				dp[i][j]+=dp[0][j-1];
			else if(j==0 && i>0)
				dp[i][j]+=dp[i-1][0];
			else dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);	
		}
	}
	return dp[m-1][n-1];
}
int main()
{
	int m,n;
	cin>>m>>n;
	int **mat=new int*[m];
	
	for(int i=0;i<m;i++)
	{
		mat[i]=new int[n];
		for(int j=0;j<n;j++)
		cin>>mat[i][j];
	}
	

cout<<recur_min_cost(mat,m,n)<<endl;
cout<<dynamic_min_cost(mat,m,n);
}
