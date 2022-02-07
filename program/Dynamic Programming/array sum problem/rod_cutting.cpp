#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int rod_cut(int *a,int *b,int w,int n)
{
	if(w<0)return INT_MIN;
	if(n<1 || w==0)return 0;
	if(w-b[n-1]>=0)
	 return max(rod_cut(a,b,w,n-1),rod_cut(a,b,w-b[n-1],n)+a[n-1]);
	else return rod_cut(a,b,w,n-1);
}

int dynamic(int *a,int *b,int w,int n)
{
if(w<0)return INT_MIN;
	if(n<1 || w==0)return 0;
	
	if(dp[n][w]==0)
	{
		if(w-b[n-1]>=0)
	 dp[n][w] = max(rod_cut(a,b,w,n-1),rod_cut(a,b,w-b[n-1],n)+a[n-1]);
	else dp[n][w] = rod_cut(a,b,w,n-1);
	}
	
	return dp[n][w];
}


int rodCut(int *price, int n)
{
	int T[n + 1];
	for (int i = 0; i <= n; i++)
		T[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			T[i] = max(T[i], price[j - 1] + T[i - j]);
	return T[n];
}
int main()
{
	int n;
	cin>>n;
	int *v=new int[n];
	int *l=new int[n];
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n;i++)
		cin>>l[i];
		int w;
	cin>>w;
	
	cout<<rod_cut(v,l,w,n)<<endl;
	
	cout<<dynamic(v,l,w,n)<<endl;
	cout<<rodCut(v,w);
}
