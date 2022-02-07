#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
	
	map<T,list<T> > adj;
	public:
		Graph()
		{
			
		}
		
		void addedge(T u,T v,bool bidir=true)
		{
			adj[u].push_back(v);
			if(bidir)
				adj[v].push_back(u);
		}
		
		void printgraph()
		{
			for(auto row:adj)
			{
				cout<<row.first<<" --> ";
				for(auto node:row.second)
				{
					cout<<node<<",";
				}
				cout<<endl;
			}
		}
		
		void bfs(T src,T dest)
		{
			queue<T> q;
			q.push(src);
			bool *vis=new bool[100]{0};
			int *dis=new int[100]{0};
			int *parent=new int[100];
			for(int i=0;i<100;i++)
				parent[i]=-1;
				
			vis[src]=1;
			while(!q.empty())
			{
				T key=q.front();
				q.pop();
				cout<<key<<" ";
				
				for(auto node:adj[key])
				{
					if(vis[node]==0)
					{
						q.push(node);
						vis[node]=1;
						dis[node]=dis[key]+1;
						parent[node]=key;
					}
				}
			}
			
			cout<<endl;
			cout<<" shortest dist of every node from src node is:"<<endl;
			int n=sizeof(dis)/sizeof(int);
			for(int i=0;i<6;i++)
			    cout<<dis[i]<<" ";
			 cout<<endl;
			 cout<<"shortest distance for destination "<<dis[dest]<<endl;
			cout<<"shortest path from "<<src<<" to "<<dest<<endl;
			
			while(dest!=-1)
			{
			    cout<<dest<<"<--";
			    dest=parent[dest];
			}
		}
};

int main()
{
		Graph<int> g;
	g.addedge(0,1);
	g.addedge(0,4);
	g.addedge(1,2);
	g.addedge(2,4);
	g.addedge(2,3);
	g.addedge(3,4);
	g.addedge(3,5);

	g.printgraph();
	cout<<endl;
	g.bfs(0,5);
}
