#include<bits/stdc++.h>
using namespace std;

int calculate1s(int **g,int n)
{
	int l[n][n],r[n][n],t[n][n],b[n][n];
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(t,0,sizeof(t));
	memset(b,0,sizeof(b));
	
	for(int i=0;i<n;i++)
	{
		l[i][0]=g[i][0];
		t[0][i]=g[0][i];
		r[i][n-1]=g[i][n-1];
		b[n-1][i]=g[n-1][i];
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(g[i][j]==1)
				l[i][j]=1+l[i][j-1];
			if(g[j][i]==1)
				t[j][i]=1+t[j-1][i];
			if(g[i][n-1-j]==1)
				r[i][n-1-j]=1+r[i][n-j];
			if(g[n-1-j][i]==1)
				b[n-1-j][i]=1+b[n-j][i];
		}
	}
	int bar=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int len=min( min(l[i][j],r[i][j]),min(t[i][j],b[i][j]));
			bar=max(bar,len);
		}
	}
	return bar;
}
int main()
{
	int **g;
	int n;
	cin>>n;
	
	g=new int*[n];
	
	for(int i=0;i<n;i++)
	{
		g[i]=new int[n];
		for(int j=0;j<n;j++)
		cin>>g[i][j];
	}
	
	int bar=calculate1s(g,n);
	cout<<bar<<endl;
	cout<<((4*bar)-(3));
}
