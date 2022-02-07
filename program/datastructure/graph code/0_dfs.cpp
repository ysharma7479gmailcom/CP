#include<bits/stdc++.h>
using namespace std;

class graph{
	int v,e;
	unordered_map<int,vector<int>> adj;
	public:
		graph(int n,int m)
		{
			v=n;
			e=m;
		}
		
		void add(int x1,int x2)
		{
			adj[x1].push_back(x2);
		}
		
		void dfs(int i,int *vis)
		{
			cout<<i<<" ";
			vis[i]=1;
			for(auto x:adj[i])
				if(vis[x]==0)
					dfs(x,vis);
			return;
		}
		
};

int main()
{
	int n,m;
	cin>>n>>m;
	graph g(n,m);
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		g.add(u,v);
	}
	int *vis=new int[n]{0};
	g.dfs(0,vis);
}
