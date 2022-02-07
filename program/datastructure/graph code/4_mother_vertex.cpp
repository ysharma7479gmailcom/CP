/*
Case 1:- Undirected Connected Graph : In this case, all the vertices are mother vertices as we can reach 
													to all the other nodes in the graph.
Case 2:- Undirected/Directed Disconnected Graph : In this case, there is no mother vertices as we cannot reach to a
													ll the other nodes in the graph.
Case 3:- Directed Connected Graph : In this case, we have to find a vertex -v in the graph such that we can reach to
									 all the other nodes in the graph through a directed path.
*/

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
		void dfs(int *vis,int i)
		{
			vis[i]=1;
			for(auto x:adj[i])
				if(vis[x]==0)
					dfs(vis,x);
		}
		int mother_vertex()
		{
			int *vis=new int[v];
			for(int i=0;i<v;i++)vis[i]=0;
			int j;
			for(int i=0;i<v;i++)
			{
				if(vis[i]==0)
				{
					dfs(vis,i);
					j=i;
					cout<<j<<endl;
				}
			}
			
			for(int i=0;i<v;i++)vis[i]=0;
			cout<<j<<"dsd"<<endl;
			dfs(vis,j);
			for(int i=0;i<v;i++)if(vis[i]==0)return -1;
			
			return j;
		}
		
};
int main()
{
	int n,m;
	cin>>n>>m;
	graph g(4);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		g.add(u,v);
	}
	
	cout<<g.mother_vertex()<<endl;
}
//doubt
