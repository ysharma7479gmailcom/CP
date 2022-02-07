#include<bits/stdc++.h>
using namespace std;

int max_sum_submatrix(int **g,int m,int n,int k)
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
	
	int t,max=INT_MIN;
	pair<int,int> p;
	for(int i=k-1;i<m;i++)
	{
		for(int j=k-1;j<n;j++)
			{
				t=sum[i][j];
				if(i-k>=0)
					t=t-sum[i-k][j];
				if(j-k>=0)
					t=t-sum[i][j-k];
				if(i-k>=0 && j-k>=0)
					t=t+sum[i-k][j-k];
				if(max < t)
				{
				max=t;
				p=make_pair(i,j);
			}
				}	
	}	
	cout<<p.first<<" "<<p.second<<endl;
	return max;
	
}
int main()
{
	int n,m,k;
	cin>>m>>n>>k;
	
	int **g=new int*[m];
	for(int i=0;i<m;i++)
	{
		g[i]=new int[n];
		for(int j=0;j<n;j++)
		cin>>g[i][j];
	}
	cout<<max_sum_submatrix(g,m,n,k);
}
