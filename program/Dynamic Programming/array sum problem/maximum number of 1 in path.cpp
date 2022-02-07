#include<bits/stdc++.h>
using namespace std;
int ans=0;
int dp[100][100];
int number_of_1s(int **p,int i,int j,int n)
{
	if(i>=n || j>=n || j<0 )
	return 0;
	if(p[i][j]==-1)
		return 0;
	
	if(i%2==0)
		return max(number_of_1s(p,i+1,j,n),number_of_1s(p,i,j+1,n)) + p[i][j];
	return max(number_of_1s(p,i+1,j,n),number_of_1s(p,i,j-1,n)) + p[i][j];
	
	
}

int dyna(int **p,int i,int j,int n)
{
	if(i>=n || j>=n || j<0 )
	return 0;
	if(p[i][j]==-1)
		return 0;
	
	if(dp[i][j]==0)
	{
		if(i%2==0)
			dp[i][j]=p[i][j] + max(dyna(p,i+1,j,n),dyna(p,i,j+1,n));
		else
			dp[i][j]=p[i][j] + max(dyna(p,i+1,j,n) , dyna(p,i,j-1,n));
	}
	return dp[i][j];
}
int main()
{
	int n;
	cin>>n;
	
	int **p=new int*[n];
	for(int i=0;i<n;i++)
	{
		p[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>p[i][j];
		}
	}
	 
	 cout<<number_of_1s(p,0,0,n)<<endl;
	 cout<<ans<<endl;
	 cout<<dyna(p,0,0,n);
}
