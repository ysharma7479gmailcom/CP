#include<bits/stdc++.h>
using namespace std;

class graph{
	int v;
	unordered_map<int,vector<int>> adj;
	public:
		graph(int n)
		{
			v=n;
		}
		void add(int x,int y)
		{
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		bool dfs(int i,int *vis,int pr)
		{
			vis[i]=1;
			for(auto x:adj[i])
			{
				if(vis[x]==0)
				{
					if(dfs(x,vis,i))
					 	return true;
				}
				else if(vis[x]==1 && x!=pr)return true;
			}
			return false;
		}
		bool cycle()
		{
			int *vis=new int[v];
			for(int i=0;i<v;i++)
				vis[i]=0;
			for(int i=0;i<v;i++)
				if(vis[i]==0 && dfs(i,vis,-1))
					return true;
			return false;
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
	cout<<g.cycle();
}
