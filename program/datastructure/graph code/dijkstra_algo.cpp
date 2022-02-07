#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <limits.h> 
  using namespace std;
// A structure to represent a node in adjacency list 
struct AdjListNode 
{ 
    int dest; 
    int weight; 
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
struct AdjList 
{ 
    struct AdjListNode *head;  // pointer to head node of list 
}; 
  
// A structure to represent a graph. A graph is an array of adjacency lists. 
// Size of array will be V (number of vertices in graph) 
struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  
// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest, int weight) 
{ 
    struct AdjListNode* newNode = 
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->weight = weight; 
    newNode->next = NULL; 
    return newNode; 
} 
  
// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
  
    // Create an array of adjacency lists.  Size of array will be V 
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
  
     // Initialize each adjacency list as empty by making head as NULL 
    for (int i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 
  
// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest, int weight) 
{ 
    // Add an edge from src to dest.  A new node is added to the adjacency 
    // list of src.  The node is added at the beginning 
    struct AdjListNode* newNode = newAdjListNode(dest, weight); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
  
    // Since graph is undirected, add an edge from dest to src also 
    newNode = newAdjListNode(src, weight); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
} 
 

 
void dijkstra(struct Graph* graph, int src,int t) 
{ 
    int V = graph->V;// Get the number of vertices in graph 
    int dist[V];      // dist values used to pick minimum weight edge in cut 
  
    // minHeap represents set E 
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    // Initialize min heap with all vertices. dist value of all vertices  
    
  
    // Make dist value of src vertex as 0 so that it is extracted first 
   
    dist[src] = 0; 
    
  
   
    while (!isEmpty(minHeap)) 
    { 
        // Extract the vertex with minimum distance value 
        struct MinHeapNode* minHeapNode = extractMin(minHeap); 
        int u = minHeapNode->v; // Store the extracted vertex number 
  
        // Traverse through all adjacent vertices of u (the extracted 
        // vertex) and update their distance values 
        struct AdjListNode* pCrawl = graph->array[u].head; 
        while (pCrawl != NULL) 
        { 
            int v = pCrawl->dest; 
  
            // If shortest distance to v is not finalized yet, and distance to v 
            // through u is less than its previously calculated distance 
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&  
                                          pCrawl->weight + dist[u] < dist[v]) 
            { 
                dist[v] = dist[u] + pCrawl->weight; 
  
                // update distance value in min heap also 
                decreaseKey(minHeap, v, dist[v]); 
            } 
            pCrawl = pCrawl->next; 
        } 
    } 
  
    // print the calculated shortest distances 
   cout<<dist[t]; 
} 
  
  

int main() {
   int n,m;
	cin>>n>>m;
	struct Graph* graph = createGraph(n);
		for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		addEdge(graph, u, v, w); 
	}
	int s,t;
	cin>>s>>t;
	s--;t--;
	dijkstra(graph, s,t); 
	return 0;
}
