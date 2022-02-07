#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int recur_gold_pot(int *a,int i,int j)
{
	if(i==j)
			return a[i];
	if(i+1==j)
			return max(a[i],a[j]);
	
	return max( a[i] + min(recur_gold_pot(a,i+2,j),recur_gold_pot(a,i+1,j-1)) , a[j] +min(recur_gold_pot(a,i+1,j-1),recur_gold_pot(a,i,j-2)));
	
}

int dynamic(int *a,int i,int j)
{
	if(i==j)
			return a[i];
	if(i+1==j)
			return max(a[i],a[j]);
	if(dp[i][j]==0)
	{
		dp[i][j]=max( a[i] + min(dynamic(a,i+2,j),dynamic(a,i+1,j-1)) , a[j] +min(dynamic(a,i+1,j-1),dynamic(a,i,j-2)));
	}
	return dp[i][j];
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<recur_gold_pot(a,0,n-1)<<endl;
	cout<<dynamic(a,0,n-1);
}
