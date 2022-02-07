#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	int v;
	map<T,vector<T>> adj;
	public:
		Graph()
		{
			
		}
		
		void addEdge(T u,T v,bool bidir=false)
		{
			adj[u].push_back(v);
			if(bidir)
				adj[v].push_back(u);
		}
		
		bool cycle()
		{
			int *vis=new int[adj.size()]{0};
			int *restack=new int[adj.size()]{0};
			
			for(int i=0;i<adj.size();i++)
				if(!vis[i] && helper(i,vis,restack))
					return true;
			return false;
		}
		
		bool helper(int src,int *vis,int *res)
		{
		
				vis[src]=1;
				res[src]=1;
				
				for(int i=0;i<adj[src].size();i++)
					{
						if(!vis[adj[src][i]] && helper(adj[src][i],vis,res))
							return true;
						if(res[adj[src][i]])
							return true;
					}
		
			
			res[src]=0;
			return false;
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
    
    cout<<g.cycle();	
}


//bool cyclic(int i, int V, vector<int> adj[],bool visited[], bool inTheCall[])
//{
//  
//    visited[i]=true;
//    inTheCall[i]=true;
//    for(int j =0;j<adj[i].size();j++)
//    { 
//        if(!visited[adj[i][j]] &&  cyclic(adj[i][j],V,adj,visited,inTheCall))
//        {
//            return true;
//        }
//        else{
//            if(inTheCall[adj[i][j]])
//            return true;
//        }
//    }
//    
//    inTheCall[i]=false;
//    return false;
//}
//bool isCyclic(int V, vector<int> adj[])
//{
//    bool visited[V];
//    bool inTheCall[V];
//    for(int  i=0;i<V;i++)
//    {
//        visited[i]=false;
//        inTheCall[i]= false;
//    }
//    
//    for(int i =0;i<V;i++)
//    {  if(!visited[i]){
//      if(cyclic(i,V,adj,visited,inTheCall))
//      return true;
//    }
//    }
//    return false;
//}
