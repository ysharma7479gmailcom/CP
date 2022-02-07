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
		 		cout<<row.first<<"-->  ";
		 		
		 		for(auto node:row.second)
		 		{
		 			cout<<node<<",";
				 }
				 cout<<endl;
			 }
		 }
};  

int main()
{
	Graph<string> g;
	g.addedge("delhi","patna");
	g.addedge("delhi","agra");
	g.addedge("delhi","goa");
	g.addedge("goa","patna");
	g.addedge("agra","goa");
	
	g.printgraph();
}
