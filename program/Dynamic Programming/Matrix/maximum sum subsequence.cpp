#include<bits/stdc++.h>
using namespace std;
int dp[100],r=0,d=0;
int max_subseque_sum(int *a,int n)
{
	r++;
	if(n<=0)return 0;
	
	return max( max_subseque_sum(a,n-1) , max_subseque_sum(a,n-2)+a[n-1]);
}
int dynamic(int *a,int n)
{
	d++;
	if(n<=0)return 0;
	if(dp[n]==0)
	{
		dp[n]=max(dynamic(a,n-1) , dynamic(a,n-2)+a[n-1]);
	}
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	cout<<max_subseque_sum(a,n)<<endl;
	
	cout<<dynamic(a,n)<<endl;
	cout<<" r ->"<<r<<"  d-> "<<d<<endl;
}
