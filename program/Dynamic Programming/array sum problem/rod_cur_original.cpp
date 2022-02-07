#include<bits/stdc++.h>
using namespace std;

int rod_cut(int *a,int n)
{
	if(n==0)
			return 0;
	
	int m=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		int cost=a[i-1]+rod_cut(a,n-i);
		m=max(m,cost);
	}
	return m;
}

int dynamic(int *p,int n)
{
	vector<int> v(n+1,0);
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<i+1;j++)
		{
			v[i]=max(v[i],p[j-1]+v[i-j]);
		}
	}
	return v[n];
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
	int *p=new int[n];
	
	for(int i=0;i<n;i++)
		cin>>p[i];
	int w;
	cin>>w;
	cout<<rod_cut(p,w)<<endl;
	cout<<dynamic(p,w);
	
	cout<<rodCut(p,w)<<endl;
}
