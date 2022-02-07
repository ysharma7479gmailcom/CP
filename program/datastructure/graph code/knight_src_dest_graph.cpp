#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    int V,n1;
    map<T,vector<T>> adj;
    public:
    Graph(int x,int x1)
    {
        V=x;
        n1=x1;
    }
    
    void add(T u,T v,bool bidir=false)
    {
        if(v.first<0 || v.first>n1 || v.second<0 || v.second>n1)return;
        adj[u].push_back(v);
        if(bidir)
            adj[v].push_back(v);
    }
    
    int bfs(T src,T dest)
    {
        map<T,bool> vis;
        map<T,int> dis;
        dis[src]=0;
        vis[src]=1;
        queue<T> q;
        q.push(src);
        
        while(!q.empty())
        {
            T key=q.front();
            q.pop();
            //cout<<key.first<<" "<<key.second<<" "<<dis[key]<<endl;
            auto it=adj[key].begin();
            for(;it!=adj[key].end();it++)
            {
                if(vis[*it]==0)
                {
                    vis[*it]=1;
                    dis[*it]=dis[key]+1;
                    q.push(*it);
                }
            }
            
        }
        return dis[dest];
    }
    
};
int main()
{
int t;
cin>>t;
while(t--)
{
   int n;
   cin>>n;
   
   Graph<pair<int,int>> g(n*n,n);
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           pair<int,int> p;
           p=make_pair(i,j);
           g.add(p,make_pair(i+1,j+2));
           g.add(p,make_pair(i+1,j-2));
           g.add(p,make_pair(i-1,j+2));
           g.add(p,make_pair(i-1,j-2));
           g.add(p,make_pair(i+2,j+1));
           g.add(p,make_pair(i-2,j+1));
           g.add(p,make_pair(i+2,j-1));
           g.add(p,make_pair(i-2,j-1));
       }
   }
   pair<int,int> q1,q2;
   cin>>q1.first>>q1.second>>q2.first>>q2.second;
   q1.first--;
   q1.second--;
   q2.first--;
   q2.second--;
   cout<<g.bfs(q1,q2)<<endl;
}
}
