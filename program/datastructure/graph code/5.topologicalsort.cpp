#include<bits/stdc++.h>
using namespace std;

class graph{
	int v;
	map<int,vector<int>> adj;

	public:
			vector<int> top;
		graph(int n)
		{
			v=n;
		}
		
		void add(int u,int v)
		{
			adj[u].push_back(v);
		}
		
		void dfs(int *vis,int i)
		{
			vis[i]=1;
			for(auto v:adj[i])
				if(vis[v]==0)
					dfs(vis,v);
			top.push_back(i);
		}
		void topo()
		{
			int *vis=new int[v]{0};
			for(int i=0;i<v;i++)
			{
				if(vis[i]==0)
					{
						dfs(vis,i);
					}
			}
			return;
		}
};
int main()
{
	int n,m;
	cin>>n>>m;
	
	graph g(n);
	
	for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			g.add(u,v);
		}
	g.topo();
	for(int j=0;j<g.top.size();j++)
		cout<<g.top[g.top.size()-1-j]<<" ";
}
