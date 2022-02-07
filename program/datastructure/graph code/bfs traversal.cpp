#include<bits/stdc++.h>
using namespace std;

void bfs(vector< int> v[],int n)
{
	
	int *vis=new int[n];
	int *dis=new int[n];
	for(int i=0;i<n;i++)vis[i]=0;
	queue<int> q;
	vis[2]=1;
	q.push(2);

	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(int i=0;i<v[x].size();i++)
		{
			//cout<<a[x][i]<<endl;
			if(vis[v[x][i]]==0)
				{
					q.push(v[x][i]);
					vis[v[x][i]]=1;
				}
		}
		
	}
	return;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> v[n];
	
	
		for(int j=0;j<m;j++)
			{
				int u,x,w;
				cin>>u>>x>>w;
				v[u].push_back(x);
				v[x].push_back(u);
			}
	
	bfs(v,n);
}
