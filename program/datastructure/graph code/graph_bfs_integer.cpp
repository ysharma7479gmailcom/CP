#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
	
	map<T,list<T>> adj;
	public:
		Graph(){
			
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
				cout<<row.first<<" ->> ";
				for(auto node:row.second)
					cout<<node<<" , ";
				cout<<endl;
			}
		}
		
		void bfs(T src)
		{
		    cout<<"sd"<<endl;
			queue<T> q;
			//T *vis=new T[100]{"0"};
			map<T,int> vis;
			vis[src]=1;
			q.push(src);
			
			while(!q.empty())
			{
				T key=q.front();
				cout<<key<<" ";
				q.pop();
				
				for(int node:adj[key])
				{
					if(vis[node]==0)
					{
						q.push(node);
						vis[node]=1;
					}
				}
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

// Graph<string> g;
// 	g.addedge("delhi","patna");
// 	g.addedge("delhi","agra");
// 	g.addedge("delhi","goa");
// 	g.addedge("goa","patna");
// 	g.addedge("agra","goa");
	
	g.printgraph();
	cout<<endl;
	g.bfs(0);
}
