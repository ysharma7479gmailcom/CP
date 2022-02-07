#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> v[],int n,int m,int i,int j)
{
	v[i][j]=0;
static int row[]={ -1, -1, -1, 0, 0, 1, 1, 1 }; 
static int col[]={ -1, 0, 1, -1, 1, -1, 0, 1 };

	for(int x=0;x<8;x++)
	{
		int r=i+row[x];
		int c=j+col[x];
		if(r>=0 && c>=0 && r<n && c<m && v[r][c]==1)
			dfs(v,n,m,r,c);
	}
	return;
}
int no_of_islands(vector<int> v[],int n,int m)
{
	int ans=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(v[i][j]==1)
			{
				dfs(v,n,m,i,j);
				ans++;
			}
		}
	}
	return ans;
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<int> v[n];
for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}

cout<<no_of_islands(v,n,m);
}
