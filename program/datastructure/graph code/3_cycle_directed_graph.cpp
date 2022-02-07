#include<bits/stdc++.h>
using namespace std;

class graph{
	int v;
	map<int,vector<int>> adj;
	public:
		graph(int n)
		{
			v=n;
		}
		void add(int u,int v)
		{
			adj[u].push_back(v);
		}
		
		bool dfs(int *vis,int *res,int i)
		{
			vis[i]=1;
			res[i]=1;
			for(auto v:adj[i])
			{
				if(vis[v]==0)
				{
					if(dfs(vis,res,v))
					return true;
				}
				else{
				if(res[v]==1)return true;
				}
			}
			res[i]=0;
			return false;
		}
		bool iscycle()
		{
			int *vis=new int[v];
			int *res=new int[v];
			for(int i=0;i<v;i++)
			{
				vis[i]=0;
				res[i]=0;
			}
			for(int i=0;i<v;i++)
			{
				if(vis[i]==0 && dfs(vis,res,i))
					return true;
			}
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
	cout<<g.iscycle()<<endl;
}
