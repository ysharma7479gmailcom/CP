#include<bits/stdc++.h>
using namespace std;

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
