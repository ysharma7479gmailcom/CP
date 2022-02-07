#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	
	public:
		Graph(int v)
		{
			V=v;
			adj=new list<int>[V];
		}
		
		void addedge(int u,int v,bool bidir=true)
		{
			adj[u].push_back(v);
			if(bidir)
				adj[v].push_back(u);
		}
		
		void printlist()
		{
			for(int i=0;i<V;i++)
			{
				cout<<i<<"--> ";
				list<int> iterator:: it;
				it=adj[i].begin();
			for(;it!=adj[i].end();it++)
					{
					cout<<(*it)<<"->";
			}
				cout<<endl;
			}
		}
};
int main()
{
	Graph g(4);
	
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(0,3);
	g.addedge(1,3);
	g.addedge(3,2);
	
	g.printlist();
}
