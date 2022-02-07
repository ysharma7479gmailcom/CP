#include<bits/stdc++.h>
using namespace std;

int max_sum_submatrix(int **g,int m,int n,int p,int q,int r,int s)
{
	int sum[m][n];
	
	sum[0][0]=g[0][0];
	for(int i=1;i<n;i++)
		sum[0][i]=g[0][i]+sum[0][i-1];
	for(int j=1;j<m;j++)
		sum[j][0]=g[j][0]+sum[j-1][0];
		
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			sum[i][j]=sum[i][j-1]+sum[i-1][j] + g[i][j] - sum[i-1][j-1];
		}
	}
	
	int ans=sum[r][s];
	if(q-1>=0)
		ans=ans-sum[r][q-1];
	if(p-1>=0)
		ans=ans-sum[p-1][s];
	if(p-1>=0 && q-1>=0)
		ans=ans-sum[p-1][q-1];
	
	return ans;
	
}
int main()
{
	int n,m;
	cin>>m>>n;
	
	int **g=new int*[m];
	for(int i=0;i<m;i++)
	{
		g[i]=new int[n];
		for(int j=0;j<n;j++)
		cin>>g[i][j];
	}
	int p,q,r,s;
	cin>>p>>q>>r>>s;
	cout<<max_sum_submatrix(g,m,n,p,q,r,s);
}
