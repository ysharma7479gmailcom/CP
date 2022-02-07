#include<bits/stdc++.h>
using namespace std;

int max_sum_sub_matrix(int **g,int n,int m)
{
	int sum[m+1][n+1];
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
				sum[i][j]=0;
			else sum[i][j]=sum[i-1][j]+sum[i][j-1]+g[i-1][j-1]-sum[i-1][j-1];
		}
	}
	
	int max=INT_MIN;
	for(int r1=0;r1<m;r1++)
	{
		for(int r2=r1;r2<m;r2++)
		{
			for(int c1=0;c1<n;c1++)
			{
				for(int c2=c1;c2<n;c2++)
				{
					int temp_sum=sum[r2+1][c2+1]-sum[r2+1][c1]-sum[r1][c2+1]+sum[r1][c1];
					if(temp_sum > max)
						max=temp_sum;
				}
			}
		}
	}
	return max;
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
	
	cout<<max_sum_sub_matrix(g,n,m);
}
