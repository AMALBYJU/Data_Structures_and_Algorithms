#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct edge
{
 int src,dest,weight;
};

struct graph
{
 int vertices;
 int edges;
 struct edge *E;
};

struct graph *creategraph(int vertices,int edges)
{
 struct graph *G = (struct graph*)malloc(sizeof(struct graph));
 G->vertices = vertices;
 G->edges = edges;
 G->E = (struct edge*)malloc(edges * sizeof(struct edge));
 return G;
}

void printarr(int arr[],int n)
{
 int i;
 printf("Vertex      Distance\n");
 for(i = 0;i<n; i++)
  printf("%d      -       %d\n",i,arr[i]);
  
}

void bellmanford(struct graph *G,int src) 
{
 int i,j;
 int dist[G->vertices];
 
 for(i=0;i< G->vertices ; i++)
  dist[i] = INT_MAX;

 dist[src] = 0;
   
 for(i = 0;i < G->vertices-1;i++)
 {
  for(j=0;j< G->edges ; j++)
  {
   int u = G->E[j].src;
   int v = G->E[j].dest;
   int w = G->E[j].weight;
   if(dist[u] != INT_MAX && ((dist[u] + w) < dist[v]))
   {
    dist[v] = dist[u] + w;
   }
  }
 }
 
 for(j=0;j< G->edges ; j++)
 {
  int u = G->E[j].src;
  int v = G->E[j].dest;
  int w = G->E[j].weight;
  
  if(dist[u] != INT_MAX && ((dist[u] + w) < dist[v]))
  {
    printf("Negative cycle exists in graph\n");
    break;
  }
 }
 printarr(dist,G->vertices);
}

int main()
{
    /* Let us create the graph given in above example */
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    struct graph* graph = creategraph(V, E);
 
    // add edge 0-1 (or A-B in above figure)
    graph->E[0].src = 0;
    graph->E[0].dest = 1;
    graph->E[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph->E[1].src = 0;
    graph->E[1].dest = 2;
    graph->E[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph->E[2].src = 1;
    graph->E[2].dest = 2;
    graph->E[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph->E[3].src = 1;
    graph->E[3].dest = 3;
    graph->E[3].weight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph->E[4].src = 1;
    graph->E[4].dest = 4;
    graph->E[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->E[5].src = 3;
    graph->E[5].dest = 2;
    graph->E[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph->E[6].src = 3;
    graph->E[6].dest = 1;
    graph->E[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->E[7].src = 4;
    graph->E[7].dest = 3;
    graph->E[7].weight = -3;
    
    // Starting vertex is assumed to be 0
    bellmanford(graph, 0);
 
    return 0;
}

     
