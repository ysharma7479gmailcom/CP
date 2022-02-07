#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
	int v;
	map<T,list<T> > adj;
	public:
		Graph(int x)
		{
			v=x;
		}
		
		void addEdge(T u,T v,bool bidir=true)
		{
			adj[u].push_back(v);
			if(bidir)
				adj[v].push_back(u);
		}
		
		void dfs(int src)
		{
			int *vis=new int[v]{0};
			
			dfs_util(src,vis);
				
		}
		
		void dfs_util(int src,int *vis)
		{
			vis[src]=1;
			cout<<src<<" ";
			for(auto x:adj[src])
				if(vis[x]==0)
					dfs_util(x,vis);
		}
};
int main()
{
	Graph<int> g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    
    g.dfs(0);
}
