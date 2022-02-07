#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int recur_longest_seq(int **m,int i,int j,int n)
{
	if(i>=n || j>=n)return 1;
	int x=0,y=0;
	if(i<n-1 && abs(m[i+1][j]-m[i][j])==1)
		x=recur_longest_seq(m,i+1,j,n)+1;
	else x=recur_longest_seq(m,i+1,j,n);
	
	if(j<n-1 && abs(m[i][j+1]-m[i][j])==1)
		y=recur_longest_seq(m,i,j+1,n)+1;
	else y=recur_longest_seq(m,i,j+1,n);
	
	return max(x,y);
}

int dynamic(int **m,int i,int j,int n)
{
	if(i>=n || j>=n)return 1;
	if(dp[i][j]==0)
	{
		int x=0,y=0;
	if(i<n-1 && abs(m[i+1][j]-m[i][j])==1)
		x=dynamic(m,i+1,j,n)+1;
	else x=dynamic(m,i+1,j,n);
	
	if(j<n-1 && abs(m[i][j+1]-m[i][j])==1)
		y=dynamic(m,i,j+1,n)+1;
	else y=dynamic(m,i,j+1,n);
	
	dp[i][j]=max(x,y);
	}
	return dp[i][j];
}
int main()
{
	int n;
	cin>>n;
	int **m=new int*[n];
	
	for(int i=0;i<n;i++)
	{
		m[i]=new int[n];
		for(int j=0;j<n;j++)
		cin>>m[i][j];
	}
	
	cout<<recur_longest_seq(m,0,0,n)<<endl<<dynamic(m,0,0,n);
}
